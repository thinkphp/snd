def main():
 
    n = int(input())
    s = 0
    upper = math.sqrt(n)    
    i = 1;
    while i <= upper:
          if n % i == 0:
              j = n // i
              if j != i:
                  s += i + j
              else:
                  s += i
          i += 1
    print(s)
 
main()
