#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"
#include "funcionario.h"

// typedef struct empresa {
//     int id;
//     tFuncionario** funcionarios; //Ponteiro duplo pois será um vetor (alocado dinamicamente) para ponteiros de Funcionarios
//     int qtdFuncionarios;
// } tEmpresa;

/**
 * @brief Cria uma empresa "vazia"
 *
 * Seus atributos devem ser inicializados com NULL (ponteiros), ou -1 caso contrário
 * @return TEmpresa* Ponteiro para empresa criada a partir do Id fornecido.
 */
tEmpresa *CriaEmpresa()
{
    tEmpresa *e = (tEmpresa *)calloc(1, sizeof(tEmpresa));
    if (e == NULL)
    {
        printf("Deu ruim na aolcacao de empresa\n");
        exit(1);
    }
    e->funcionarios = NULL;
    e->id = -1;
    e->qtdFuncionarios = -1;
    return e;
}

/**
 * @brief Le os dados de uma empresa da entrada padrao.
 * @param *empresa - ponteiro para empresa que terá seus dados preenchidos
 */
void LeEmpresa(tEmpresa *empresa)
{
    scanf(" %d\n", &empresa->id);
}

/**
 * @brief Libera toda a memória alocada dinamicamente para uma empresa
 * @param *empresa - ponteiro para empresa que terá seus dados apagados e memória liberada
 */
void ApagaEmpresa(tEmpresa *empresa)
{
    for (int i = 0; i < empresa->qtdFuncionarios; i++)
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
    for (int i = 0; i < empresa->qtdFuncionarios; i++)
    {
        if (GetIdFuncionario(empresa->funcionarios[i]) == GetIdFuncionario(funcionario))
        {
            return;
        }
    }
    
}

/**
 * @brief Imprime todos os dados de um empresa.
 *
 * @param empresa Ponteiro para Empresa a ser impressa no terminal.
 */
void ImprimeEmpresa(tEmpresa *empresa)
{
    printf("Empresa %d:\n");
    for (int i = 0; i < empresa->qtdFuncionarios; i++)
    {
        ImprimeFuncionario(empresa->funcionarios[i]);
    }
}
