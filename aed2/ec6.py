lista_subconjuntos = []
def subsetsUtil(array, subset, index):
  if subset != []:
    lista_subconjuntos.append(list(subset))
  for i in range(index, len(array)):
    subset.append(array[i])
    subsetsUtil(array, subset, i + 1)
    subset.pop()
  return 


def subsets(array):
  global res
  subset = []
  index = 0
  subsetsUtil(array, subset, index)
  print('\n')

  resposta = []
  for i in lista_subconjuntos:
    if sum(i) % 2 != 0:
      resposta.append(i)
  print('Resposta:')
  print(resposta)
  print('\n')

  return

array = [1, 2, 3, 4, 6, 7 ,9]

subsets(array)