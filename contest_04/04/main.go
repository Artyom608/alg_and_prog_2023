package main

import (
    "encoding/csv"
    "fmt"
    "io/ioutil"
    "sort"
    "strconv"
    "strings"
)

type Passenger struct {
    Name string
    Age  float64
}

func main() {
    var pclass, age int

    // Запрос у пользователя значений pclass и age.
    _, err := fmt.Scanf("%d", &pclass)
    if err != nil {
        fmt.Println("Ошибка при вводе pclass:", err)
        return
    }

    _, err = fmt.Scanf("%d", &age)
    if err != nil {
        fmt.Println("Ошибка при вводе age:", err)
        return
    }

    // Открываем файл "train.csv" для чтения.
    b, err := ioutil.ReadFile("train.csv")
    if err != nil {
        fmt.Println("Ошибка при чтении файла:", err)
        return
    }
    str := string(b)
    str = strings.Replace(str, "\r", "\n", -1)

    // Создаем CSV-ридер для обработанного содержимого.
    reader := csv.NewReader(strings.NewReader(str))
    reader.Comma = ','

    // Считываем строки из файла.
    lines, err := reader.ReadAll()
    if err != nil {
        fmt.Println("Ошибка при чтении файла:", err)
        return
    }

    // Пройдем по строкам и выполним необходимые действия.
    var passengers []Passenger

    for _, line := range lines {
        // Проверяем, что строка имеет необходимое количество полей.
        if len(line) < 6 {
            continue
        }

        // Извлекаем данные из строки с учетом возможного отсутствия данных.
        pclassStr := line[2]
        ageStr := line[5]
        name := line[3]
        sex := line[4]

        pclassInt, _ := strconv.Atoi(pclassStr)
        ageFloat, _ := strconv.ParseFloat(ageStr, 64)

        // Устанавливаем нули для отсутствующих данных.
        if pclassStr == "" {
            pclassInt = 0
        }
        if ageStr == "" {
            ageFloat = 0.0
        }

        if sex == "female" && (pclassInt == pclass) && ageFloat > float64(age) {
            passengers = append(passengers, Passenger{Name: name, Age: ageFloat})
        }
    }

    // Функция для сравнения пассажиров.
    less := func(i, j int) bool {
        if passengers[i].Age != passengers[j].Age {
            return passengers[i].Age < passengers[j].Age
        }
        return passengers[i].Name < passengers[j].Name
    }

    // Сортируем пассажиров.
    sort.SliceStable(passengers, func(i, j int) bool {
        return less(i, j)
    })

    // Выводим отсортированных пассажиров.
    for _, passenger := range passengers {
        fmt.Println(passenger.Name)
    }
}
