package main

import (
    "encoding/json"
    "fmt"
    "io/ioutil"
)

func main() {
    jsonData, err := ioutil.ReadFile("data.json")
    if err != nil {
        fmt.Println("Ошибка чтения файла:", err)
        return
    }

    var data []map[string]interface{}

    if err := json.Unmarshal(jsonData, &data); err != nil {
        fmt.Println("Ошибка разбора JSON:", err)
        return
    }
    
    var user_id_inp, completed_tasks int
    fmt.Scanf("%d",&user_id_inp)
    
    for _, item := range data {
        tasks := item["tasks"].([]interface{})
        for _, task := range tasks {
            taskMap := task.(map[string]interface{})
            userID := int(taskMap["user_id"].(float64))
            completed := taskMap["completed"].(bool)

            if userID == user_id_inp && completed {
                completed_tasks++
            }
        }
    }
    fmt.Println(completed_tasks)
}
