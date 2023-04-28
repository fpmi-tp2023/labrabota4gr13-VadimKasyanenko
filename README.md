# Overview
Напишите консольное приложение на языке C, которое устанавливает
соединение с БД SQLite и выполняет запросы типа SELECT, INSERT, DELETE,
параметризованные запросы, фотографию объекта выводит в файл. Структура
проекта приложения должна соответствовать модели КИС и содержать Makefile для
сборки с помощью утилиты make.
Иллюстрирует вставку данных в режиме autocommit (исполнение инструкций
sqlite построчно) и транзакцией.

Требования к приложению:

• Структура проекта приложения размещается в каталоге project6, должна
соответствовать модели КИС и содержать Makefile для сборки с помощью
утилиты make.

• наличие меню для выбора операций с приложением;

• возможность ввода параметра для выборки;

• по id,

• по шаблону для разных полей, например фрагменту названия продукта или
фрагменту фамилии,

• полю, общему для нескольких строк, например в зависимости от варианта
это может быть название категории товара, или специальности, или города
и т.д.

• запросы должны быть описаны в коде приложения (без выполнения в
консоли);

• содержит функционал для демонстрации вставки данных в режиме
autocommit (исполнение инструкций sqlite построчно) и транзакцией

# Usage
Выполнение лабораторной работы 4
# Building
Используем makefile и запускаем файл program в папке bin
# Additional notes

Репозиторий содержит 2 ветки:

Ветка examples содержит код выполненных примеров 

Ветка dev содержит код задания 6

