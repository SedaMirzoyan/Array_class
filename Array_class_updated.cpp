
#include <iostream>

class Array {
private:
    int* ptr;
    int size;

public:
    Array()
    {
        std::cout << "Default constructor\n";
        size = 0;
        ptr = nullptr;
    }

    Array(int n)
    {
        std::cout << "Parametrized constructor\n";
        size = n;
        ptr = new int[size];
    }

    ~Array()
    {
        std::cout << "Destructor\n";
        delete[]ptr;
    }

    Array(const Array& ob)
    {
        std::cout << "Copy constructor\n";
        this->size = ob.size;

        this->ptr = new int[size];

        for (int i = 0; i < size; i++)
        {
            this->ptr[i] = ob.ptr[i];
        }
    }

    Array& operator=(const Array& ob)
    {
        if (this != &ob)
        {
            std::cout << "Operator assignment\n";
            this->size = ob.size;
            delete[]ptr;

            this->ptr = new int[this->size];

            for (int i = 0; i < size; i++)
            {
                this->ptr[i] = ob.ptr[i];
            }
        }
        return *this;
    }

    Array operator[](int index) const
    {
        if (index > size || index < 0)
        {
            throw std::logic_error("Out of range\n");
        }
        std::cout << "Element with value " << ptr[index] << " was returned\n";
        return ptr[index];
    }


    int* genElements()
    {
        for (int i = 0; i < size; i++)
        {
            ptr[i] = rand() % 100 + 1;
        }
        return ptr;
    }


    int getElement(int index)
    {
        if (index > size || size < 0)
        {
            std::cout << "Out of range\n";
            return -1;
        }
        else
        {
            std::cout << "Element with value " << ptr[index] << " was returned\n";
            return ptr[index];
        }
    }

    void printArray()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << "element[" << i << "] = " << ptr[i] << std::endl;
        }
    }
};


int main()
{
    int n;
    std::cout << "Enter the number of elements\n";
    std::cin >> n;

    Array ob(n);
    ob.genElements();
    ob.printArray();
    //ob.getElement(3);

    /*try {
        ob[-1];
    }
    catch (const std::logic_error& e)
    {
        std::cerr << e.what();
    }*/


    try {
        ob[3];
    }
    catch (const std::logic_error& e)
    {
        std::cerr << e.what();
    }

    Array ob_cp(ob);

    Array ob1;
    ob1 = ob_cp;

    return 0;
}
