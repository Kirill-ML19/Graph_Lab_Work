# Graph Lab Work

## Описание

Лабораторная работа по теме "Парсинг графов и их рендеринг". Программа выполняет парсинг графов, представленных в текстовых файлах, и генерирует визуальные представления этих графов в формате BMP. Программа поддерживает несколько типов графов, таких как бинарные деревья, сетки, звезды и другие.

## Функциональность

- **Парсинг графов**: Графы читаются из текстовых файлов с определенным форматом (с количеством вершин и рёбер, а затем с парами вершин, которые соединены рёбром).
- **Генерация изображений**: Каждый граф визуализируется в виде изображения в формате BMP.
- **Поддержка различных типов графов**:
  - **Binary Tree**: Бинарное дерево.
  - **Grid**: Сетка.
  - **Non-Planar**: Непланарный граф.
  - **Pentagram**: Пентаграмма.
  - **Star**: Звезда.
  - **Sun**: Солнечный граф.

## Структура проекта

```
Graph_Lab_Work/
├── Makefile                # Makefile для компиляции проекта
├── README.md               # Документация проекта
├── includes/               # Папка с заголовочными файлами
│   ├── Graph.h
│   ├── Parser.h
│   └── Renderer.h
├── src/                    # Папка с исходными файлами
│   ├── Graph.cpp
│   ├── Parser.cpp
│   ├── Renderer.cpp
│   └── main.cpp
├── data/                   # Папка с примерами графов
│   ├── Binary_Tree.txt
│   ├── Grid.txt
│   ├── Non-Planar.txt
│   ├── Pentagram.txt
│   ├── Star.txt
│   └── Sun.txt
└── images/                 # Папка для сохраненных изображений BMP
```
## Требования

- **Операционная система**: Для компиляции и запуска достаточно Linux, Windows или macOS.
- **C++11 или выше**: Для компиляции используется C++11 или более новая версия.
- **CMake или Makefile**: Для сборки проекта используется CMake или Makefile.
- **Инструменты**:
  - Компилятор C++ (например, `g++` или `clang++`).
  - Для работы с проектом и его сборки используйте команду `make` или CMake.

## Процесс установки

1. Клонируйте репозиторий:

   ```bash
   git clone https://github.com/Kirill-ML19/Graph_Lab_Work
   cd Graph_Lab_Work ```
2. Установка зависимостей: 
    Для работы с лабораторной не требуются сторонние библиотеки, так как лабораторная работа использует стандартную библиотку C++
3. Сборка: 
    Для сборки спользуем `Makefile`
    ```bash
    make```
4. Запуск программы:
    ```bash
    make run```
5. Очистка файлов сборки:
    ```bash
    make clean```