gtest = dependency('gtest', main: true)
test(
    'func',
    executable(
        'func_test',
        sources: ['functions_test.cpp'],
        include_directories: src,
        dependencies: [gtest]
    )
)