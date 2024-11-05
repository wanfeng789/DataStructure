


add_executable(01_AdjacentMatrix 01_AdjacentMatrix/main.c
        01_AdjacentMatrix/adjacentMatrix.c
        01_AdjacentMatrix/adjacentMatrix.h

)
add_executable(02_Adjacent_List 02_Adjacent_List/main.c
        02_Adjacent_List/adjacentList.c
        02_Adjacent_List/adjacentList.h
)

add_executable(03_CrossLinker 03_CrossLinker/main.c
                                03_CrossLinker/crossLinker.c
                                03_CrossLinker/crossLinker.h
)
add_executable(04_Adjacent_Multi_List 04_Adjacent_Multi_List/main.c
        04_Adjacent_Multi_List/adjacencyMultiList.c
        04_Adjacent_Multi_List/adjacencyMultiList.h
)
add_executable(05_Kruskal 05_Kruskal/main.c
        05_Kruskal/Kruskal.c
        05_Kruskal/Kruskal.h
        01_AdjacentMatrix/adjacentMatrix.h
        01_AdjacentMatrix/adjacentMatrix.c
)
add_executable(06_Prim 06_Prim/main.c
        06_Prim/Prim.c
        06_Prim/Prim.h
        01_AdjacentMatrix/adjacentMatrix.h
        01_AdjacentMatrix/adjacentMatrix.c
)
#包含头文件
target_include_directories(05_Kruskal PRIVATE 01_AdjacentMatrix)
target_include_directories(06_Prim PRIVATE 01_AdjacentMatrix)