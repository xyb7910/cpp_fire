#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

const int N = 110;

// 矩阵涉及的操作：
// 	数学操作：加法 减法 乘法 转置 求逆（余子式，行列式，伴随矩阵）
// 	几何操作：顺指针90度 逆时针90度 180度

// 矩阵加法
std::vector<std::vector<int>>& addMatrices(std::vector<std::vector<int>> &a, const std::vector<std::vector<int>> &b) {
	int n = a.size();
	int m = a[0].size();
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			a[i][j] += b[i][j];
		}
	}
	return a;
}


// 矩阵减法
std::vector<std::vector<int>>& subtractMatrices(std::vector<std::vector<int>> &a, const std::vector<std::vector<int>> &b) {
	int n = a.size();
	int m = a[0].size();
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			a[i][j] -= b[i][j];
		}
	}
	return a;
}


// 矩阵乘法
// n * p p * m = n * m
std::vector<std::vector<int>> multiplyMatrices(const std::vector<std::vector<int>> &a, const std::vector<std::vector<int>> &b) {
	int n = a.size();
	int p = a[0].size();
	int m = b[0].size();
	std::vector<std::vector<int>> res(n, std::vector<int>(m, 0));

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			for (int k = 0; k < p; k ++) {
				res[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return res;
}

// 求矩阵的转置矩阵 
std::vector<std::vector<int>> transposeMatrices(const std::vector<std::vector<int>> &a) {
	int n = a.size();
	int m = a[0].size();

	std::vector<std::vector<int>> res(n, std::vector<int>(m, 0));
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			res[j][i] = a[i][j];
		}
	}
	return res;
}


// 获取矩阵余子式
std::vector<std::vector<int>> getMinor(const std::vector<std::vector<int>> &matrix, int row, int col) {
    std::vector<std::vector<int>> minor;
    for (int i = 0; i < matrix.size(); ++i) {
        if (i == row) continue;
        std::vector<int> minorRow;
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (j == col) continue;
            minorRow.push_back(matrix[i][j]);
        }
        minor.push_back(minorRow);
    }
    return minor;
}

// 计算矩阵行列式
int determinant(const std::vector<std::vector<int>> &matrix) {
    if (matrix.size() == 1) {
        return matrix[0][0];
    }
    if (matrix.size() == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    int det = 0;
    for (int i = 0; i < matrix.size(); ++i) {
        det += (i % 2 == 0 ? 1 : -1) * matrix[0][i] * determinant(getMinor(matrix, 0, i));
    }
    return det;
}

// 计算伴随矩阵
std::vector<std::vector<int>> adjugateMatrix(const std::vector<std::vector<int>> &matrix) {
    int n = matrix.size();
    std::vector<std::vector<int>> adj(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            adj[j][i] = ((i + j) % 2 == 0 ? 1 : -1) * determinant(getMinor(matrix, i, j));
        }
    }
    return adj;
}


// 逆矩阵
std::vector<std::vector<int>> inverseMatrix(const std::vector<std::vector<int>> &a) {
	int det = determinant(a);
    if (det == 0) {
        throw std::runtime_error("Matrix is singular and cannot be inverted.");
    }
    std::vector<std::vector<int>> adj = adjugateMatrix(a);
    for (auto& row : adj) {
        for (auto& element : row) {
            element /= det;
        }
    }
    return adj;
}

// 旋转矩阵 顺指针90度
std::vector<std::vector<int>> rotateMatrixClockwise90(const std::vector<std::vector<int>> &a) {
	int n = a.size();
	int m = a[0].size();

	std::vector<std::vector<int>> res(n, std::vector<int>(m, 0));
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			res[j][n - 1 - i] = a[i][j];
		}
	}
	return res;
}

// 旋转矩阵 逆时针90度
std::vector<std::vector<int>> rotateMatrixCounterClockwise90(const std::vector<std::vector<int>> &a) {
	int n = a.size();
	int m = a.size();

	std::vector<std::vector<int>> res(n, std::vector<int>(m, 0));
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			res[n - 1 - j][i] = a[i][j];
		}
	}
	return res;
}

// 旋转矩阵 180度
std::vector<std::vector<int>> rotateMatrix180(const std::vector<std::vector<int>> &a) {
	int n = a.size();
	int m = a.size();

	std::vector<std::vector<int>> res(n, std::vector<int>(m, 0));
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			res[n - 1 - i][n - 1 - j] = a[i][j];
		}
	}
	return res;
}