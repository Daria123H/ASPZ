Посилання:https://github.com/Daria123H/ASPZ.git

# Завдання 10.21

   Реалізуйте програму, яка створює два дочірні процеси, кожен з яких виводить своє повідомлення.
   
## Виконання

Пишемо [код](https://github.com/Daria123H/ASPZ/blob/main/Pr10/PR10.py), який  створює два дочірні процеси за допомогою os.fork(). Кожен із них виводить своє повідомлення й завершується через os._exit(0). Головний (батьківський) процес чекає завершення обох дочірніх процесів за допомогою os.waitpid() і виводить підсумкове повідомлення. 
Запускаємо: 

    python3 PR10.py

### Результат

 ![Результат](https://github.com/Daria123H/ASPZ/blob/main/Pr10/PR10.png)



