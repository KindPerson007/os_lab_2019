CC=gcc
CFLAGS=-I.

# Сборка всех программ
all: sequential_min_max parallel_min_max runner

# Сборка sequential_min_max
sequential_min_max: utils.o find_min_max.o utils.h find_min_max.h
    $(CC) -o sequential_min_max find_min_max.o utils.o sequential_min_max.c $(CFLAGS)

# Сборка parallel_min_max
parallel_min_max: utils.o find_min_max.o utils.h find_min_max.h
    $(CC) -o parallel_min_max utils.o find_min_max.o parallel_min_max.c $(CFLAGS)

# Сборка runner
runner: runner.c
    $(CC) -o runner runner.c $(CFLAGS)

# Объектные файлы
utils.o: utils.h
    $(CC) -o utils.o -c utils.c $(CFLAGS)

find_min_max.o: utils.h find_min_max.h
    $(CC) -o find_min_max.o -c find_min_max.c $(CFLAGS)

clean:
    rm -f utils.o find_min_max.o sequential_min_max parallel_min_max runner
