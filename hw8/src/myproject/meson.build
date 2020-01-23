myproject_src =files([
    'main.cpp', 'merge_sort.h'
])
threads = dependency('threads')
executable(
    'hw8',#название исполняемого файла
    include_directories: src,#где ищутся заголовочные файлы
    sources: myproject_src,#список исходный файлов
    dependencies: [threads],#зависимости проекта (если имеются)
    install:true#устанавливать ли файл
)
