#include <iostream>
#include <exception>
#include <string>

using namespace std;

float Divide(float a, float b)
{
    float res = 0.0;
    if (b == 0)
    {
        throw "Can't divide by zero";
    }
    if (b == 1)
    {
        throw 404;
    }
    if (b == 2)
    {
        throw std::exception("Can't divide by zero");
    }
    else
    {
        res = a / b;
    }

    return res;
}

class PasswordInvalidException : public std::exception
{
public:
    PasswordInvalidException(const  char* message) : std::exception(message) {}
};

class PasswordShortException : public std::exception
{
private:
    int length;
public:
    PasswordShortException(const  char* message, int length) : length(length), std::exception(message) {}

    void Message()
    {
        std::cout << what() << std::endl;
        std::cout << "Real length of pass os : " << length << std::endl;
    }
};

void Login(const char* login, const char* pass)
{
    if (strlen(pass) < 6)
    {
        throw PasswordShortException("Your pass if too short ", strlen(pass));
        /* std::cout << "Your pass if too short" << std::endl;*/
    }
    if (!isalpha(pass[0]) || !islower(pass[0]))
    {
        throw PasswordInvalidException("Invalid pass ");
        /* std::cout << "Invalid pass " << std::endl;*/
    }
    if (!isalpha(login[0]) || !islower(pass[0]))
    {
        throw  std::exception("Login is invalid ");
        /*    std::cout << "Login is invalid " << std::endl;*/
    }
}

class Array
{
private:
    int size;
    int* arr;

public:
    Array(int size = 10) : size(size)
    {
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % 99;
        }
    }

    Array(const Array& other) : size(other.size)
    {
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = other.arr[i];
        }
    }

    void Print() const
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    int& operator[](int index)
    {
        if (index >= 0 && index < size)
        {
            return arr[index];
        }
        else
        {
            throw std::out_of_range("Error: Index ");
        }
    }

    void ChackSize(int size)
    {
        if (size < 0)
        {
            throw std::length_error("Negative number can't use ...");
        }
        else
        {
            std::cout << "Size is valid " << std::endl;
        }
    }

    void SetSize(int newSize)
    {
        if (newSize <= 0)
        {
            throw std::invalid_argument("New size can't be used...");
            /*std::cout << "New size can't be used..." << std::endl;*/
            return;
        }

        int* new_arr = new int[newSize];
        for (int i = 0; i < size && i < newSize; i++)
        {
            new_arr[i] = arr[i];
        }

        delete[] arr;
        arr = new_arr;
        size = newSize;
    }

    ~Array()
    {
        delete[] arr;
    }
};

class Stack
{
    enum { EMPTY = -1, FULL = 9 };
    int data[FULL + 1];
    int topIndex;
public:
    Stack()
    {
        topIndex = EMPTY;
    }
    ~Stack() = default;
    bool IsFull()const
    {
        return topIndex == FULL;
    }
    bool Push(int element)
    {
        if (!IsFull())
        {
            data[++topIndex] = element;
        }
        else
        {
            throw std::overflow_error("Stack is full. Can't push element");
        }
    }
    bool IsEmpty()const
    {
        return topIndex == EMPTY;
    }
    int Pop()
    {
        if (!IsEmpty())
        {
            return data[topIndex--];
        }
        else
        {
            throw std::underflow_error("Stack is empty. Cannot pop element.");
        }
    }
    int Peek()
    {
        if (!IsEmpty())
        {
            return data[topIndex];
        }
        else
        {
            throw std::underflow_error("Stack is empty. Cannot peek element.");
        }
    }
    int GetCount()const
    {
        return topIndex + 1;
    }
    void Clear()
    {
        topIndex = EMPTY;
    }
};

int ConvertToInt(const std::string& str)
{
    try
    {
        size_t pos;
        int result = std::stoi(str, &pos);

        if (pos != str.length())
        {
            throw std::out_of_range("Value is out of the range of int");
        }

        return result;
    }
    catch (const std::invalid_argument&)
    {
        throw std::invalid_argument("Invalid input: not a valid integer");
    }
    catch (const std::out_of_range&)
    {
        throw std::out_of_range("Value is out of the range of int");
    }
};

    int main()
    {
        std::string input;
        std::cout << "Enter an integer: ";
        std::cin >> input;

        try
        {
            int result = ConvertToInt(input);
            std::cout << "Converted integer: " << result << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Error: " << ex.what() << std::endl;
        }



       /* Stack st;
        try
        {
            st.Push(35);
            std::cout << "Count: " << st.GetCount() << std::endl;
            st.Push(11);
            st.Push(88);
            st.Push(55);
            st.Push(55);
            st.Push(55);
            st.Push(55);
            st.Push(55);
            st.Push(55);
            st.Push(99);
            st.Push(100);
            std::cout << "Count: " << st.GetCount() << std::endl;
            std::cout << "Element: " << st.Pop() << std::endl;
            std::cout << "Count: " << st.GetCount() << std::endl;

            while (!st.IsEmpty())
            {
                std::cout << "Element: " << st.Pop() << std::endl;
            }
            std::cout << "Count: " << st.GetCount() << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Error: " << ex.what() << std::endl;
        }*/

        /* Array arr(5);
         arr.Print();
         arr[2] = 10;
         arr.Print();
         try
         {
             arr[7] = 777;
             arr.Print();
             arr.SetSize(-4);
             arr.Print();
         }
         catch (const std::out_of_range&ex)
         {
             std::cout << ex.what() << std::endl;
         }
         catch (const std::invalid_argument& ex)
         {
             std::cout << ex.what() << std::endl;
         }
         try
         {
             arr.ChackSize(-1);
         }
         catch (const std::length_error&ex)
         {
             std::cout << ex.what() << std::endl;
         }*/

         /* char login[100];
          char pass[100];

          for (size_t i = 0; i < 5; i++)
          {
              std::cout << "Enter Login: " << std:: endl;
              std::cin >> login;
              std::cout << "Enter pass : " << std::endl;
              std::cin >> pass;
              try
              {
                  Login(login, pass);
              }
              catch (const char * ex)
              {
                  std::cout << ex << std::endl;
              }
              catch (const std::exception& ex)
              {
                  std::cout << ex.what() << std::endl;
              }
              catch (PasswordInvalidException& ex)
              {
                  std::cout << ex.what() << std::endl;
                  std::cout << "You can enter only A-Z as first symbol " << std::endl;
              }
              catch (PasswordShortException& ex)
              {
                  std::cout << "Too short pass.Length of your pass must be more that 6 " << std::endl;
                  ex.Message();
              }
              catch (const std::exception& ex)
              {
                  std::cout << ex.what() << std::endl;
              }
          }*/

          /*int a, b;
          std::cout << "Enter a and b: " << std::endl;
          std::cin >> a >> b;
          try
          {
              std::cout << Divide(a, b);
          }
          catch (const char* ex)
          {
              std::cout << ex << std::endl;
          }
          catch (int ex)
          {
              std::cout << ex << std::endl;
          }
          catch (const std::exception& ex)
          {
              std::cout << ex.what() << std::endl;
          }
          catch (...)
          {
              std::cout << "Unknown exception" << std::endl;
          }
          std::cout << "Continue..." << std::endl;
          return 0;*/
        return 0;
    }
