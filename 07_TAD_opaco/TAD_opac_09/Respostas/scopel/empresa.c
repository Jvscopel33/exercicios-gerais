#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"
#include "funcionario.h"

struct empresa
{
  int id;
  int qtdFuncEntrada;
  int qtdFuncionariosAlocados;
  tFuncionario **funcionarios;
};

int ExisteIdNaEmpresa(tEmpresa *empresa, int id);

/**
 * @brief Cria uma empresa "vazia"
 *
 * Seus atributos devem ser inicializados com NULL (ponteiros), ou -1 caso contrário
 * @return TEmpresa* Ponteiro para empresa criada a partir do Id fornecido.
 */
tEmpresa *CriaEmpresa()
{
  tEmpresa *e = (tEmpresa *)calloc(1, sizeof(tEmpresa));
  e->funcionarios = NULL;
  e->id = -1;
  e->qtdFuncEntrada = -1;
  e->qtdFuncionariosAlocados = -1;
  return e;
}

/**
 * @brief Le os dados de uma empresa da entrada padrao.
 * @param *empresa - ponteiro para empresa que terá seus dados preenchidos
 */
void LeEmpresa(tEmpresa *empresa)
{
  empresa->qtdFuncionariosAlocados = 0;
  scanf(" %d %d\n", &empresa->id, &empresa->qtdFuncEntrada);
  empresa->funcionarios = (tFuncionario **)calloc(empresa->qtdFuncEntrada, sizeof(tFuncionario *));
}

/**
 * @brief Libera toda a memória alocada dinamicamente para uma empresa
 * @param *empresa - ponteiro para empresa que terá seus dados apagados e memória liberada
 */
void ApagaEmpresa(tEmpresa *empresa)
{
  for (int i = 0; i < empresa->qtdFuncionariosAlocados; i++)
  {
    ApagaFuncionario(empresa->funcionarios[i]);
  }
  free(empresa->funcionarios);
  free(empresa);
}

/**
 * @brief Adiciona um funcionario a uma empresa caso o id do funcionario ainda nao esteja registrado na empresa.
 *
 * @param empresa Ponteiro para Empresa em que o funcionario deve ser adicionado.
 * @param funcionario Ponteiro para Funcionario que deve ser adicionado a empresa.
 */
void ContrataFuncionarioEmpresa(tEmpresa *empresa, tFuncionario *funcionario)
{
  if (!ExisteIdNaEmpresa(empresa, GetIdFuncionario(funcionario)))
  {
    empresa->funcionarios[empresa->qtdFuncionariosAlocados] = funcionario;
    empresa->qtdFuncionariosAlocados++;
  }
  else
  {
    printf("A empresa %d ja possui um funcionario com o id %d\n", empresa->id, GetIdFuncionario(funcionario));
    free(funcionario);
  }
}

/**
 * @brief Imprime todos os dados de um empresa.
 *
 * @param empresa Ponteiro para Empresa a ser impressa no terminal.
 */
void ImprimeEmpresa(tEmpresa *empresa)
{
  printf("Empresa %d:\n", empresa->id);
  for (int i = 0; i < empresa->qtdFuncionariosAlocados; i++)
  {
    ImprimeFuncionario(empresa->funcionarios[i]);
  }
}

int ExisteIdNaEmpresa(tEmpresa *empresa, int id)
{
  for (int i = 0; i < empresa->qtdFuncionariosAlocados; i++)
  {
    if (id == GetIdFuncionario(empresa->funcionarios[i]))
    {
      return 1;
    }
  }
  return 0;
}