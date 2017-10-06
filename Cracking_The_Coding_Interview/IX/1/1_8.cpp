#include <iostream>
#include <vector>
#include <map>

std::vector< std::vector<int> > zeroMatrix(std::vector< std::vector<int> >a, int m, int n)
{
        std::map<int, bool> row_occ, col_occ;
        std::vector<int> row, col;

        int i, j;
        for (i = 0; i < m; i++) {
                for (j = 0; j < n; j++) {
                        if (a[i][j] == 0) {
                                if (!row_occ[i]) {
                                        row_occ[i] = true;
                                        row.push_back(i);
                                }
                                if (!col_occ[j]) {
                                        col_occ[j] = true;
                                        col.push_back(j);
                                }
                        }
                }
        }

        for (i = 0; i < row.size(); i++) {
                for (j = 0; j < n; j++) {
                        a[ row[i] ][j] = 0;
                }
        }

        for (i = 0; i < col.size(); i++) {
                for (j = 0; j < m; j++) {
                        a[ j ][col[i]] = 0;
                }
        }

        return a;
}

void printMatrix(std::vector< std::vector<int> > a, int m, int n, std::string str)
{
        std::cout << str << std::endl;
        int i, j;
        for (i = 0; i < m; i++) {
                for (j = 0; j < n; j++)
                        std::cout << a[i][j] << " ";
                std::cout << "\n";
        }
}

int main()
{
        int m, n, i, j;
        std::cin >> m >> n;

        std::vector< std::vector<int> > a(m, std::vector<int>(n));

        for (i = 0; i < m; i++)
                for (j = 0; j < n; j++)
                        std::cin >> a[i][j];

        a = zeroMatrix(a, m, n);
        printMatrix(a, m, n, "Zero Matrix:");
}
