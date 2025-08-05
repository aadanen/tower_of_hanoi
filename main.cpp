#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>

typedef struct Post {
  std::stack<int> stk;
  std::string name;
} Post;

int moves = 0;

void solve(int n, Post &src, Post &dst, Post &aux) {
  if (n == 1) {
    int ring;
    ring = src.stk.top();
    printf("Move ring %d from %s to %s\n", ring, src.name.c_str(),
           dst.name.c_str());
    moves++;
    src.stk.pop();
    dst.stk.push(ring);
  } else {
    solve(n - 1, src, aux, dst);
    solve(1, src, dst, aux);
    solve(n - 1, aux, dst, src);
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: ./a.out <num_rings>\n");
    return 1;
  }
  int n = atoi(argv[1]);
  printf("Solving tower of hanoi for %d rings\n", n);
  Post A;
  A.stk = std::stack<int>();
  A.name = "A";
  Post B;
  B.stk = std::stack<int>();
  B.name = "B";
  Post C;
  C.stk = std::stack<int>();
  C.name = "C";

  for (int i = n; i > 0; i--) {
    A.stk.push(i);
  }
  solve(n, A, C, B);
  printf("Number of moves: %d\n", moves);

  return 0;
}
