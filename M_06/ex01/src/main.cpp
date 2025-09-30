#include "Serializer.hpp"

int main(void)
{
    {
        Data    data;

        data.key = 0;
        data.value = "valor";

        Data    *originalPtr = &data;

        //Serialize
        uintptr_t raw = Serializer::serialize(originalPtr);
        std::cout
                << "Serialize value: "
                << raw
                << std::endl;
        
        //Deserialize
        Data *recoverPtr = Serializer::deserialize(raw);
        std::cout
                << "Deserialize key: "
                << recoverPtr->key
                << "\nDeserialize value: "
                << recoverPtr->value
                << std::endl;

        //Verification
        if (recoverPtr == originalPtr)
        {
            std::cout
                    << "Works"
                    << std::endl;
        }
        else
        {
            std::cout
                    << "Doesn't works"
                    << std::endl;
        }
    }
}