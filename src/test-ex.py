import os,sys

# python test_flex  +  number of test_case you want to check
while True:
    test_case = int(input("please input the # of test_case: "))
    FILE_NAME = "test_"
    if test_case <=5: 
        FILE_NAME = FILE_NAME + str(test_case)
    else:
        print("Invalid test_case: " + test_case)
        sys.exit(1)
    command = "../bin/splc.out ../test-ex/" + FILE_NAME + ".spl"
    os.system(command)