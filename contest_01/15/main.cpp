#include <string>
using namespace std;
string compress(string& input) 
{
    int length = input.length();
    //cout<<length;
    // Если строка короткая или пустая, не сжимаем
    if (length <= 1) {
        return input; 
    }

    string compressed_string;
    int count = 1;
    //Проходимся по нашей строчке
    for (int i = 1; i < length; i++) {
        //Если текущий символ равен предыдущему, увеличиваем счетчик на 1
        if (input[i] == input[i - 1]) 
        {
            count++; 
        } 
        else 
        {
            // Добавляем символ к результату
            compressed_string += input[i - 1]; 
            if (count > 1) 
            {
                // Добавляем количество повторений, если больше 1
                compressed_string += to_string(count); 
            }
            count = 1; 
        }
    }

    // Добавляем последний символ и его повторения (если есть)
    compressed_string += input[length - 1];
    if (count > 1) 
    {
        compressed_string += to_string(count);
    }

    return compressed_string;
}

int main() 
{
    string input;
    cin >> input;
    string compressed_string = compress(input);
    cout<<compressed_string<< endl;
}
