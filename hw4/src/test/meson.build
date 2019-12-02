gtest = dependency('gtest', main: true)
matrix = executable(
        'matrix_test_exe',
        sources: ['matrix_test.cpp'],
        include_directories: src,
        dependencies: [gtest]
    )
test('matrix_test', matrix)
    
guard = executable(
        'guard_test_exe',
        sources: ['guard_test.cpp'],
        include_directories: src,
        dependencies: [gtest]
    )
test('guard_test', guard)