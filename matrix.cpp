#include <iostream>
#include <chrono>
#include <string>
using namespace std;
using namespace std::chrono;

int matrix(int N)
{
  // Initialize matrices A, B, C.
  int A[N][N], B[N][N], C[N][N];
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      A[i][j] = i * N + j;
      B[i][j] = j * N + i;
      C[i][j] = 0;
    }
  }

  // Calculate C = A * B and find sum of C;
  int sum = 0;
  for (int i = 0; i < N; i++) // Rows
  {
    for (int j = 0; j < N; j++) // Cols
    {
      int cSum = 0;
      for (int k = 0; k < N; k++)
      {
        cSum += A[i][k] * B[k][j];
      }
      C[i][j] = cSum;
      sum += cSum;
    }
  }
  return sum;
}

int main(int argc, char ** argv)
{
  if (argc != 2)
    cout << "Please provide a number!" << '\n';
  else
  {
    int sum;
    int N = atoi(argv[1]);
    high_resolution_clock::time_point begin = high_resolution_clock::now();
    sum = matrix(N);
    high_resolution_clock::time_point end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>( end - begin ).count();

    cout << sum << endl;
    cout << "The function took " << duration << " nanoseconds." << '\n';
    return 0;
  }
}
