gtest = dependency('gtest', main: true)
turn = executable(
        'turn_exe',
        sources: ['tests.cpp'],
        include_directories: src,
        dependencies: [gtest]
    )
test('turn_test', turn)