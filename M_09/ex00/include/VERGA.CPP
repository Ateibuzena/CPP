
bool BitcoinExchange::isValidValue(const std::string &valueStr, double &outValue) {
    std::string s = trim(valueStr);
    if (s.empty()) return false;

    // check characters: digits, one dot, optional leading +, maybe decimal
    int dotCount = 0;
    int digitCount = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (c == '.') {
            ++dotCount;
            if (dotCount > 1) return false;
        } else if (c == '+' || c == '-') {
            if (i != 0) return false; // only leading sign allowed
            if (c == '-') return false; // negative not allowed
        } else if (isdigit(static_cast<unsigned char>(c))) {
            ++digitCount;
        } else {
            return false;
        }
    }
    if (digitCount == 0) return false;

    // convert
    std::istringstream iss(s);
    double v;
    if (!(iss >> v)) return false;
    if (v < 0.0 || v > 1000.0) return false;

    outValue = v;
    return true;
}

void BitcoinExchange::loadDatabase(const std::string &dbFilename) {
    std::ifstream file(dbFilename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: no se pudo abrir la base de datos '" << dbFilename << "'\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        // Esperamos formato: YYYY-MM-DD,price
        if (line.empty()) continue;
        std::string::size_type commaPos = line.find(',');
        if (commaPos == std::string::npos) {
            // ignorar linea malformada pero avisar por stderr
            std::cerr << "Warning: línea malformada en DB: '" << line << "'\n";
            continue;
        }
        std::string date = trim(line.substr(0, commaPos));
        std::string priceStr = trim(line.substr(commaPos + 1));

        if (!isValidDate(date)) {
            std::cerr << "Warning: fecha inválida en DB: '" << date << "'\n";
            continue;
        }
        double price;
        if (!isValidValue(priceStr, price)) {
            // precio inválido en DB -> warning y skip
            std::cerr << "Warning: precio inválido en DB: '" << priceStr << "' (fecha " << date << ")\n";
            continue;
        }
        _prices[date] = price;
    }
    file.close();
    if (_prices.empty()) {
        std::cerr << "Warning: la base de datos quedó vacía tras la carga.\n";
    }
}

bool BitcoinExchange::getPriceForDate(const std::string &date, double &outPrice) const {
    std::map<std::string, double>::const_iterator it = _prices.lower_bound(date);
    if (it == _prices.end()) {
        if (_prices.empty()) return false;
        // tomar la última disponible
        --it;
        outPrice = it->second;
        return true;
    }
    if (it->first == date) {
        outPrice = it->second;
        return true;
    }
    // it points to first element >= date; necesitamos el anterior si existe
    if (it == _prices.begin()) {
        // no hay fecha anterior
        return false;
    }
    --it;
    outPrice = it->second;
    return true;
}

void BitcoinExchange::processInputFile(const std::string &inputFilename) const {
    std::ifstream infile(inputFilename.c_str());
    if (!infile.is_open()) {
        std::cerr << "Error: no se pudo abrir el archivo de entrada '" << inputFilename << "'\n";
        return;
    }

    std::string line;
    int lineNo = 0;
    while (std::getline(infile, line)) {
        ++lineNo;
        if (line.empty()) continue;
        // Esperamos formato: date | value
        std::string::size_type sep = line.find('|');
        if (sep == std::string::npos) {
            std::cout << "Line " << lineNo << ": Error: formato inválido (se esperaba 'date | value').\n";
            continue;
        }
        std::string date = trim(line.substr(0, sep));
        std::string valueStr = trim(line.substr(sep + 1));

        if (!isValidDate(date)) {
            std::cout << "Line " << lineNo << ": Error: fecha inválida => '" << date << "'\n";
            continue;
        }
        double value;
        if (!isValidValue(valueStr, value)) {
            std::cout << "Line " << lineNo << ": Error: valor inválido => '" << valueStr << "'\n";
            continue;
        }

        double price;
        if (!getPriceForDate(date, price)) {
            std::cout << "Line " << lineNo << ": Error: no hay precio disponible para '" << date << "' ni fecha anterior.\n";
            continue;
        }

        double result = price * value;
        // Imprimir con precisión razonable
        std::cout.setf(std::ios::fixed);
        std::cout.precision(2);
        std::cout << date << " => " << value << " = " << result << "\n";
    }

    infile.close();
}
