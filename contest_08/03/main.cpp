#include <iostream>

int* new_array(int len, int value);
int set_new_length(int** array, int old_len, int new_len);
int merge(int** dest_array, int len_dest_array, const int* src_array, int len_src_array);
int dot(const int* a, const int* b, int len);
int* find(int* array, int len, int value);
void delete_array(int** array);

int main(){
    int len_first, len_second,
        first_init_val, second_init_val;
    std::cin >> len_first >> first_init_val >> len_second >> second_init_val;
    int* first  = new_array(len_first, first_init_val);
    int* second = new_array(len_second, second_init_val);
    
    int new_len_first;
    std::cin >> new_len_first;
    len_first = set_new_length(&first, len_first, new_len_first);
    for(int i=0; i < new_len_first; i++){
        int value;
        std::cin >> value;
        first[i] = value;
    }
    
    len_second = merge(&second, len_second, first, len_first);
    
    len_second = set_new_length(&second, len_second, len_first);
    
    int value = dot(first, second, len_first);
    
    int* value_ptr;
    while( (value_ptr = find(second, len_second, value)) != nullptr ){
        *value_ptr = 0;
    }
    
    for (int i=0; i < len_second; i++) std::cout << second[i] << ' ';

    delete_array(&first);
    delete_array(&first);  // Так и задумано
    delete_array(&second);
    delete_array(&second); // Так и задумано
}

int* new_array(int len, int value) {
    // Создание массива
    int* arr = new int[len];
    for (int i = 0; i < len; ++i) {
        arr[i] = value;
    }
    return arr;
}

// Устанавливает новую длину массива.
int set_new_length(int** array, int old_len, int new_len) {
    int* new_array = new int[new_len];
    // Определяем минимальную из старой и новой длин
    int min_len = (old_len < new_len) ? old_len : new_len;
    
    // Копируем элементы из старого массива в новый
    for (int i = 0; i < min_len; ++i) {
        new_array[i] = (*array)[i];
    }
    
    // Удаляем старый массив
    delete[] *array;
    // Перенаправляем указатель на новый массив
    *array = new_array;

    // Возвращаем новую длину массива
    return new_len;
}

// Добавляет элементы из массива-источника в массив-приёмник.
int merge(int** dest_array, int len_dest_array, const int* src_array, int len_src_array) {
    //Параметр src_array - указатель на массив-источник длинной len_src_array.
    //Параметр dest_array - указатель на переменную указывающую на массив-приёмник, длина которого равна параметру len_dest_array. 
    int* new_array = new int[len_dest_array + len_src_array];
    
    // Копируем элементы из массива-приёмника в новый массив
    for (int i = 0; i < len_dest_array; ++i) {
        new_array[i] = (*dest_array)[i];
    }

    // Копируем элементы из массива-источника в новый массив
    for (int i = 0; i < len_src_array; ++i) {
        new_array[len_dest_array + i] = src_array[i];
    }

    // Удаляем старый массив-приёмник
    delete[] *dest_array;
    // Перенаправляем указатель на новый массив
    *dest_array = new_array;

    // Возвращаем новую длину массива-приёмника
    return len_dest_array + len_src_array;
}

// Вычисляет скалярное произведение.
int dot(const int* a, const int* b, int len) {
    int result = 0;
    for (int i = 0; i < len; ++i) {
        result += a[i] * b[i];
    }
    return result;
}

// Находит первое вхождение элемента равного value в массиве по адресу array заданной длины len.
int* find(int* array, int len, int value) {
    // Проходим по массиву и ищем элемент, равный value
    for (int i = 0; i < len; ++i) {
        if (array[i] == value) {
            // Возвращаем указатель на найденный элемент
            return &array[i];
        }
    }
    // Иначе возвращаем nullptr
    return nullptr;
}

// Освобождает память занятую массивом.
void delete_array(int** array) {
    // Параметр array - указатель на переменную указывающую на массив.
    delete[] *array;
    //После освобождения памяти занятой массивом указатель на массив должен стать равен nullptr. 
    *array = nullptr;
}
