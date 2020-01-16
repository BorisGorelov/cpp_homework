project('hw9',#название проекта
    'cpp',#язык
    version:'0.1.0',#версия кода
    meson_version:'>=0.46',#минимально поддерживаемая версия 
    Mesondefault_options: ['cpp_std=c++17']#используемый стандарт C++
)
subdir('src')

doxygen = find_program('doxygen')
if doxygen.found()
    run_target('doc', command: [doxygen])
endif