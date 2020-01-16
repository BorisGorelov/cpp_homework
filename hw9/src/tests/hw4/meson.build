gtest = dependency('gtest', main: true)
matrix_isStmmetric = executable(
        'matrix_isSymmetric_test_exe',
        sources: ['matrix_isSymmetric_test.cpp'],
        include_directories: src,
        dependencies: [gtest]
    )
test('matrix_isSymmetric_test', matrix_isStmmetric)

matrix_where = executable(
        'matrix_where_test_exe',
        sources: ['matrix_where_test.cpp'],
        include_directories: src,
        dependencies: [gtest]
    )
test('matrix_where_test', matrix_where)
    
guard = executable(
        'guard_test_exe',
        sources: ['guard_test.cpp'],
        include_directories: src,
        dependencies: [gtest]
    )
test('guard_test', guard)