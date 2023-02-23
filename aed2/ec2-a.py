# Exercício 1
s = [1,7,8,6,5,2]
x = 15

def ordenar_vetor(s):
    print('Ordenando o vetor "s"')
    aux = 0
    for i in range(0, len(s)):
        for j in range(0, len(s)):
            if (s[i] < s[j]):
                aux = s[i]
                s[i] = s[j]
                s[j] = aux

def subVetor(s,n,x):
  z = []
  soma = 0
  if(n == 0):
    return 0
  else:
    for i in range(0,n):
      if(soma == x):
        break
      else:
        soma += s[i]
        z.append(s[i])
        for k in range(i+1,n):
          if((soma + s[k]) <= x):
            soma += s[k]
            aux = k
            z.append(s[k])
          elif((soma - s[aux] + s[k]) == x):
            soma = soma - s[aux] + s[k]
            aux = k
            del z[-1]
            z.append(s[k])
  return z
ordenar_vetor(s)
res = subVetor(s,len(s),x)
print(res)
if(len(res) == 0 or res == 0):
  print(f'não tem uma subsequência cuja a soma seja igual a x {x}')
else:
  print(f'Existe a subsquência {res} cuja a soma seja igual ao valor de x={x}')