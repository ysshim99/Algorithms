A, B = map(int, input().split())
q, r= divmod(A, abs(B))

if B > 0:
  print(q)
  print(r)
else:
  print(-q)
  print(r)