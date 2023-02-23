c = [[]]
b = [[]]
global padrao_k

def concat(str,n):
    aux = str
    for i in range(n):
        str += aux
    return str

def achaPadrao(padrao,msg,k):
    padrao = concat(padrao,k)
    m = len(padrao)
    n = len(msg)
    for i in range(1,m): c[0[i]] = 0
    for j in range(0,n): c[j[0]] = 0
    for i in range(1,m):
        for j in range(1,n):
            if(padrao[i-1] == msg[j-1]):
                c[i[j]] = c[i[j-1]] + 1
                b[i[j]] = 1
            elif(c[i-1[j]] >=c[i[j-1]]):
                c[i[j]] = c[i-1[j]]
                b[i[j]] = 2
            else:
                c[i[j]] = c[i[j-1]]
                b[i[j]] = 3
    return c

def main():
    padrao = input("informe o padrão que deve ser achado na mensagem: ")
    n = int(input("quantidade de vezes que o padrão se repete"))
    msg = input("mensagem recebida: ")
    print(achaPadrao(padrao, msg, n))



main()
# str = 'abcdef'
# str1 = ''
# n = 4
# for i in range(n):
#     str1 += str

# print(str1)