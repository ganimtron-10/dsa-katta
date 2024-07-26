// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

func findTheCity(n int, edges [][]int, distanceThreshold int) int {
    matrix := make([][]int, n)
    for i:=0; i < n; i++ {
        matrix[i] = make([]int, n)
    }

    for _,edge := range edges {
        matrix[edge[0]][edge[1]] = edge[2]
        matrix[edge[1]][edge[0]] = edge[2]
    }

    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            if i!=j && matrix[i][j] == 0 {
                matrix[i][j] = 999999
            }
        }
    }

    fmt.Println(matrix)

    for k := 0; k < n; k++ {
        for i := 0; i < n; i++ {
            for j := 0; j < n; j++ {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j])
            }
        }
    }

    fmt.Println(matrix)

    maxNode := -1
    nodeCnt := n+1
    for node,distances := range matrix {
        cnt := 0
        for _,cost := range distances {
            if cost <= distanceThreshold {
                cnt++
            }
        }

        if nodeCnt >= cnt {
            maxNode = node
            nodeCnt = cnt
        }
    }


    return maxNode
}