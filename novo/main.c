#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DESC 50


typedef struct produto { 
        int codigo;
        char descricao[MAX_DESC];
        int qtd_estoque;
        float preco;
} Produto, *PProduto,**PPProduto;

typedef struct pedido { 
        int numero_pedido;
        PPProduto produtos;
        int indice_ult_produto_pedido;
}Pedido, *PPedido,**PPPedido;

typedef struct loja {
        PPProduto estoque;
        PPProduto carrinho;
        PPPedido pedidos_finalizados;
        int indice_ult_produto_estoque;
        int indice_ult_produto_carrinho;
        int indice_ult_pedido_finalizado;
        } Loja;
        
        
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Descartar caractere
    }
}

PProduto criar_produto(){
     PProduto produto = (PProduto) malloc(sizeof(Produto));
   if(!produto){ 
    	printf("PROBLEMA NA ALOCA��O DO PRODUTO\n\n");
    	system("PAUSE");
	}
	
   char again = 'n';
   do{
   printf("\n\n----------------------------");
   printf("\nPREENCHENDO DOS DADOS");
   printf("\n----------------------------\n");
   
   printf("Informe a Descricao do Produto: "); 
   scanf(" %[^\n]",produto->descricao);
   printf("Informe a Quantidade em estoque: "); 
   scanf("%d",&(produto->qtd_estoque));
   limparBuffer();
   printf("Informe a Valor do produto: "); 
   scanf("%f",&(produto->preco));
   limparBuffer();
   printf("\n\n----------------------------");
   printf("\nCONFERENCIA DOS DADOS");
   printf("\n----------------------------\n");
   printf("Dados digitados:\n");
   printf("Descricao '%s'\n Quantidade em estoque %d\n Preco R$ %.2f?\n\n",produto->descricao,produto->qtd_estoque,produto->preco);
   printf("Tecle 'r' para refazer o preenchimento, ou qualquer letra para confirmar:");
   scanf(" %c",&again);
   limparBuffer();
   }while(again == 'r' || again == 'R');
   
   return produto; 

}

int gerar_codigo(PPProduto* lista,int indice_ult_produto){
    int novo_codigo = -1;
   if (indice_ult_produto < 0){
            novo_codigo = 1;      
       } 
   else{
       novo_codigo = (*lista)[indice_ult_produto]->codigo + 1;
       }
	return 	novo_codigo;
    }
    
void aumentar_lista_pedidos(PPPedido* lista,int* indice_ult_pedido_finalizado){
     if (*indice_ult_pedido_finalizado < 0){
            *lista = (PPPedido) malloc(2*sizeof(PPedido));
            
         } 
     else{
            *lista = (PPPedido) realloc(*lista, (*indice_ult_pedido_finalizado+2)*sizeof(PPedido));
         }
        
     if(!lista){ 
		printf("PROBLEMA NA ALOCA��O DA LISTA\n\n");
		system("PAUSE");
		}
	 *indice_ult_pedido_finalizado = *indice_ult_pedido_finalizado + 1;
     (*lista)[*indice_ult_pedido_finalizado] = (PPedido)malloc(sizeof(Pedido));  
     (*lista)[*indice_ult_pedido_finalizado]->indice_ult_produto_pedido = -1;
     
  }
  
void aumentar_lista(PPProduto* lista,int* indice_ult_produto){
    
     if (*indice_ult_produto < 0){
            *lista = (PPProduto) malloc(sizeof(PProduto)); 
         } 
     else{
            *lista = (PPProduto) realloc(*lista, (*indice_ult_produto+2)*sizeof(PProduto));
         }
       
 
     if(!lista){ 
		printf("PROBLEMA NA ALOCA��O DA LISTA\n\n");
		system("PAUSE");
		}
	
     *indice_ult_produto = *indice_ult_produto + 1;

     
  }
void incluir_produto_estoque(PPProduto* lista,int* indice_ult_produto,PProduto pitem){
   
  
  // (*pitem)->codigo = novo_codigo;
   //*indice_ult_produto = *indice_ult_produto + 1;
 // (*lista)[*indice_ult_produto] = (*pitem);  
                                
  
  
}

int codigo_existe(PPProduto lista,int indice_ult_produto, int codigo_para_verificar,PProduto* item){
    int i;
    for(i=0; i <= indice_ult_produto; i++){
             if(lista[i]->codigo == codigo_para_verificar){
                                 *item =  lista[i];
                                 return 1;
                                 }
             }
    
    *item = NULL;
    return 0;
    }

void alterar_item(PProduto* pitem){
   int i;
   PProduto produto;  
  // for(i=0;i<=indice_ult_produto; i++){
 //                               if ((*lista)[i]->codigo == cod_item){
 //                               produto = (*lista)[i];
 //                               }
 //  }
   printf("\n\nDados atuais do produto cod(%d)\n",(*pitem)->codigo);
   printf("     Descricao: %s\n",(*pitem)->descricao);
   printf("     Quantidade em estoque: %d\n",(*pitem)->qtd_estoque);
   printf("     Valor untario: %.2f\n",(*pitem)->preco);
   
   printf("\n\n -----------------------\n");
   
   printf("\n\n Inserindo novos dados.\n\n");
   printf("Informe a nova Descricao do Produto: "); 
   scanf(" %[^\n]",(*pitem)->descricao);
   printf("Informe a nova Quantidade em estoque: "); 
   scanf("%d",&((*pitem)->qtd_estoque));
   printf("Informe o novo Valor do produto: "); 
   scanf("%f",&((*pitem)->preco));
     
   printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"); 
   printf("\n Produto alterado com sucesso!!!");
   printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");   
     }
void consultar_item(PProduto pitem, Loja* pLoja){

   PProduto produto;  
   
   printf("\n\nExibindo dados do produto cod(%d)\n",pitem->codigo);
   printf("     Descricao: %s\n",pitem->descricao);
   printf("     Quantidade em estoque: %d\n",pitem->qtd_estoque);
   printf("     Valor untario: %.2f\n",pitem->preco);
   printf("     Valor Total do estoque: %.2f\n",pitem->preco * pitem->qtd_estoque);
   printf("\n     Pedidos:\n");//IMPLEMENTAR INFORMA��ES DOS PEDIDOS DO ITEM
   if(pLoja->indice_ult_pedido_finalizado >=0){
   int i;
   for(i=0;i<=pLoja->indice_ult_pedido_finalizado;i++){
                                                    
          int j;
          for(j=0;j<=pLoja->pedidos_finalizados[i]->indice_ult_produto_pedido;j++){
                                                                      
              PProduto produtos_do_pedido =  pLoja->pedidos_finalizados[i]->produtos[j];                                                         
              if(produtos_do_pedido->codigo == pitem->codigo){
                                                             int qtd = produtos_do_pedido->qtd_estoque;
                                                             float total = qtd * produtos_do_pedido->preco;
                                                             int num_pedido = pLoja->pedidos_finalizados[i]->numero_pedido;
                                                             printf("          - %d unidades vendidas por R$ %.2f no pedido Numero '%d'.\n",qtd,total,num_pedido);          
              } 
          }                                            
   }
   
   }else{
   printf("     - Nenhum pedido finalizado com este item.\n");    
   }
     }

PProduto menu_escolha_item(PPProduto lista,int indice_ult_produto, char msgm_pergunta[], char nomeLista[]){
     
     PProduto proteiro_item = NULL;
     if(indice_ult_produto < 0 ){
     return proteiro_item;
     }
     
     int nao_existe,cod = 0;
     do{
        printf("\n\n ");
        printf(msgm_pergunta);
        scanf("%d",&cod);
        limparBuffer();
        
        nao_existe = !codigo_existe(lista,indice_ult_produto,cod,&proteiro_item);
        if(nao_existe)
        {
            printf("\n---------------------------------------------"); 
            printf("\nNENHUM ITEM NO %s COM O CODIGO '%d'...",nomeLista,cod);
            printf("\n---------------------------------------------");
            printf("\nContinuar?\n Digite 'x' para voltar ao menu:");
            char opcao; 
            scanf(" %c",&opcao);
            limparBuffer();
            if(opcao == 'x' || opcao == 'X'){
                   nao_existe = 0; 
                     }
        } 
       
            
            
                
     }while(nao_existe);
     return proteiro_item;
}

void exibir_produtos_estoque(PPProduto lista,int indice_ult_produto,int visualizacao_carrinho){
     printf("\n\n");
     char msg[30]= "NO ESTOQUE CADASTRE";
     if(visualizacao_carrinho){
                          strcpy(msg,"NO CARRINHO INCLUA");
                          }
     
     
     if(indice_ult_produto < 0){
             printf("\n ---------------------------------------------");
             printf("\nNENHUM ITEM %s ALGUM ITEM.",msg);
             printf("\n ---------------------------------------------");
             return;             
     }
     float total_geral = 0.0;
     int i;
     
     for(i=0; i <= indice_ult_produto; i++){
                 PProduto prod = lista[i];
                 float total_prod = prod->qtd_estoque * prod->preco;
                 total_geral += total_prod;
                 if(visualizacao_carrinho){
                     printf("COD: %d - %s - Qtd no pedido: %d",prod->codigo, prod->descricao, prod->qtd_estoque);
                     printf(" Preco R$ %.2f Total por item R$ %.2f\n",prod->preco,total_prod);
                     
                 }else{
                     printf("COD: %d - %s - Qtd em estoque: %d - Preco R$ %.2f\n",prod->codigo, prod->descricao, prod->qtd_estoque,prod->preco);
                     
                           }
             }
      if(visualizacao_carrinho){    
                        printf("\n\n VALOR TOTAL DO CARRINHO: R$ %.2f\n",total_geral);
     }
     }
void excluir_item(PPProduto* lista,int* indice_ult_produto, int cod_excluir){
     int i,j;
       PProduto produto_para_excluir;  
       for(i=0;i<=*indice_ult_produto; i++){
                                    if ((*lista)[i]->codigo == cod_excluir){
                                        produto_para_excluir = (*lista)[i];
                                        for (j=i+1;j<=*indice_ult_produto; j++){
                                            (*lista)[i] = (*lista)[j];
                                            i++;
                                            }
                                    }
       }
       (*lista)[*indice_ult_produto] = produto_para_excluir;
       if(*indice_ult_produto == 0){
        free((*lista));
       }else{
           *lista = (PPProduto) realloc(*lista,*indice_ult_produto*sizeof(PProduto));  
       }
       *indice_ult_produto -=1;
   printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"); 
   printf("\n Produto excluido com sucesso!!!");
   printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"); 
   printf("\n\nProduto cod.'%d' - ",cod_excluir);
   printf("%s\n",produto_para_excluir->descricao);

     }

int menu_principal_opcoes(){
	int opcao;
	system("cls");		
	printf("\n(1) Gerenciar Produto");
	printf("\n(2) Gerenciar Pedido");
	printf("\n(3) Zerar loja");
	printf("\n(4) Sair");
	printf("\n\nDigite uma opcao: ");
	scanf("%d",&opcao);
    limparBuffer();	
	return opcao;
}

int menu_gerenciar_produto_opcoes(){
	int opcao;
	system("cls");	
	printf("\n######################");
	printf("\nGerenciar Produto");
	printf("\n######################\n");
	printf("\n(1) Incluir");
	printf("\n(2) Alterar");
	printf("\n(3) Listar");
	printf("\n(4) Consultar");
	printf("\n(5) Excluir");
	printf("\n(6) Voltar");
	printf("\n\nDigite uma opcao: ");
	scanf("%d",&opcao);
    limparBuffer();	
	return opcao;

}

int menu_gerenciar_pedido_opcoes(){
	int opcao;
	system("cls");	
	printf("\n######################");
	printf("\nGerenciar Pedido");
	printf("\n######################\n");	
	printf("\n(1) Adicionar produto no carrinho");
	printf("\n(2) Consultar carrinho de compras");
	printf("\n(3) Excluir produto do carrinho");
	printf("\n(4) Alterar quantidade do produto do carrinho");	
	printf("\n(5) Finalizar Pedido");	
	printf("\n(6) Esvaziar carrinho de compras");
	printf("\n(7) Voltar");
	printf("\n\nDigite uma opcao: ");
	scanf("%d",&opcao);
    limparBuffer();	
	return opcao;
}

void gerenciar_menu_produto (Loja* pLoja){
    PPProduto* estoque = &pLoja->estoque;
    int* indice_ult_produto = &pLoja->indice_ult_produto_estoque;
    PPPedido* pedidos = &pLoja->pedidos_finalizados;
    int* indice_ult_pedido_finalizado = &pLoja->indice_ult_pedido_finalizado;
    
	int opcao;
	int sair = 0;
	do{	
		opcao = menu_gerenciar_produto_opcoes();		
		switch(opcao){
			case 1:
                
				
				char again = 'n';
                do{
                    system("CLS");
                    printf("\n######################");
    				printf("\nIncluindo Produto");
    				printf("\n######################\n");
                    PProduto produto = criar_produto();
                    produto->codigo = gerar_codigo(estoque,*indice_ult_produto);
                    aumentar_lista(estoque,indice_ult_produto);
                    (*estoque)[*indice_ult_produto] = produto;
                    //incluir_produto_estoque(estoque,indice_ult_produto,produto);
                    
                    printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"); 
                    printf("\n Produto '%s' incluido com sucesso!!!",produto->descricao);
                    printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"); 
                       
                    printf("\n\nIncluir novo Produto?\nDigite: S -> ");
                    
                    scanf(" %c",&again);
                    limparBuffer();
                }while(again == 'S' || again == 's' );
				
				
                //incluir_produto_estoque(estoque,indice_ult_produto);
                sair = 0;  
				//getch();
				break;
			case 2:
                system("CLS");
                printf("\n#################################");
				printf("\nEscolhendo Produto para alterar");
				printf("\n#################################\n");
				exibir_produtos_estoque(*estoque,*indice_ult_produto,0);
				PProduto pItem_alterar = menu_escolha_item(*estoque,*indice_ult_produto,"DIGITAR CODIGO QUE DESEJA ALTERAR: ","ESTOQUE");
				if (pItem_alterar){ 
    				system("CLS");
                    printf("\n###################################");
    				printf("\nRealizando a alteracao do Produto");
    				printf("\n###################################\n");
    				alterar_item(&pItem_alterar);
                }
				sair = 0;
				getch();
				break;								
			case 3:
                system("CLS");
                printf("\n##################################");
				printf("\nRelacao de produtos no estoque");
				printf("\n#################################\n");
				exibir_produtos_estoque(*estoque,*indice_ult_produto,0);
                sair = 0;
                getch();
				break;
			case 4:
                system("CLS");
                printf("\n######################");
				printf("\nConsultar Produto");
				printf("\n######################\n");
				
				if(*indice_ult_produto < 0){
                 printf("\n ---------------------------------------------");
                 printf("\nNENHUM ITEM NO ESTOQUE CADASTRE ALGUM ITEM.");
                 printf("\n ---------------------------------------------");
                }else{      
                PProduto pItem_consultar = menu_escolha_item(*estoque,*indice_ult_produto,"DIGITAR CODIGO QUE DESEJA CONSULTAR: ","ESTOQUE");
                    if (pItem_consultar){
                       system("CLS");
                       consultar_item(pItem_consultar,pLoja);
                    }
                }
                getch();
				break;
			case 5:
				system("CLS");
                printf("\n#################################");
				printf("\nEscolhendo Produto para Excluir");
				printf("\n#################################\n");
				exibir_produtos_estoque(*estoque,*indice_ult_produto,0);
				PProduto pItem_excluir = menu_escolha_item(*estoque,*indice_ult_produto,"DIGITAR CODIGO QUE DESEJA EXCLUIR: ","ESTOQUE");
                if (pItem_excluir){
                   system("CLS");
                   printf("\n#################################");
    			   printf("\nExcluindo Produto cod:'%d'",pItem_excluir->codigo);
    			   printf("\n#################################\n");
                   
                   excluir_item(estoque,indice_ult_produto,pItem_excluir->codigo);
                }
                sair = 0;
				getch();
				break;								
			case 6:
				printf("Voltar");
				sair = 1;
				break;
			default:
				printf("Opcao Invalida!");
				getch();
				sair = 0;			
		}
	}while(!sair);
	
}
int perguntar_quantidade(PProduto pitem_estoque,int qtd_atual){
    int qtd_desejada = -1;
     do{
                           system("CLS");
                           printf("\n#################################");
            			   printf("\n ESCOLHENDO QUANTIDADE");
            			   printf("\n#################################\n");
            			   printf("\n----------------------------------------------------------------------");
            			   if(qtd_atual){
                                         printf("\nQuantidade atual %d",qtd_atual);
                           }
            			   printf("\nQuantidade disponivel %d\nPreco unitario R$ %.2f",pitem_estoque->qtd_estoque,pitem_estoque->preco);
            			   printf("\ninformar a quantidade de '%s' desejada: ",pitem_estoque->descricao);
            			   scanf(" %d",&qtd_desejada);
                           limparBuffer();
                           if(qtd_desejada < 0 || qtd_desejada > pitem_estoque->qtd_estoque){
                                                   printf("\nQUANTIDADE INFORMADA DEVE SER ENTRE 0 E %d",pitem_estoque->qtd_estoque);
                                                   printf("\n----------------------------------------------------------------------\n");
                                                   system("PAUSE");
                                           }
            			   
                           }while(qtd_desejada < 0 || qtd_desejada > pitem_estoque->qtd_estoque);
     return qtd_desejada;
    
    }
void atualizar_estoque(PPProduto estoque,int indice_ult_produto_estoque,PPProduto carrinho,int indice_ult_produto_carrinho){
     int i;
         
         for(i=0; i<=indice_ult_produto_carrinho; i++){
                  
                  PProduto pItemNoEstoque = NULL;
                  if (codigo_existe(estoque,indice_ult_produto_estoque,carrinho[i]->codigo,&pItemNoEstoque)){
                          
                  pItemNoEstoque->qtd_estoque = pItemNoEstoque->qtd_estoque - carrinho[i]->qtd_estoque; 
                       }
                  }
     
     
     }
    
void limpar_carrinho(PPProduto* carrinho,int* indice_ult_produto_carrinho){
         int i;
         
         for(i=0; i<=*indice_ult_produto_carrinho; i++){
         free((*carrinho)[i]);
         
         }
         free((*carrinho));
         *indice_ult_produto_carrinho = -1;
     }
void gerenciar_menu_pedido(Loja* pLoja){
     
    PPProduto* estoque = &pLoja->estoque;
    int* indice_ult_produto_estoque = &pLoja->indice_ult_produto_estoque;
    
    PPProduto* carrinho = &pLoja->carrinho;
    int* indice_ult_produto_carrinho = &pLoja->indice_ult_produto_carrinho;
    
    PPPedido* pedidos = &pLoja->pedidos_finalizados;
    int* indice_ult_pedido_finalizado = &pLoja->indice_ult_pedido_finalizado;
    
	int opcao;
	int sair = 0;
	do{	
		opcao = menu_gerenciar_pedido_opcoes();		
		switch(opcao){
			case 1:
                 char again = 'n';
                 int qtd_desejada = -1;
                 do{
                system("CLS");
                printf("\n#################################");
				printf("\nAdicionando produto no carrinho");
				printf("\n#################################\n");
                exibir_produtos_estoque(*estoque,*indice_ult_produto_estoque,0);
				PProduto pItem_inserir = menu_escolha_item(*estoque,*indice_ult_produto_estoque,"DIGITAR CODIGO QUE DESEJA INCLUIR: ","CARRINHO");
                if (pItem_inserir){
                           qtd_desejada = perguntar_quantidade(pItem_inserir, 0);
                           //SE ITEM J� EST� NO CARRINHO ATUALIZAR QUANTIDADE
                           PProduto pItemNoCarrinho = NULL;
                           if (codigo_existe(*carrinho,*indice_ult_produto_carrinho,pItem_inserir->codigo,&pItemNoCarrinho)){
                                     printf("\nProduto ja estava no carrinho, quantidade foi atualizada!");                                                                                               
                                     pItemNoCarrinho->qtd_estoque = qtd_desejada;
                           }else{
                               if(qtd_desejada == 0){
                                         printf("\n\n--------------------------------------------------------- ");
                                         printf("\nNenhum item foi adicionado ao carrinho!!!");
                                         printf("\n-----------------------------------------------------------\n");      
                                               }
                               else{
                                        pItemNoCarrinho = (PProduto) malloc(sizeof(Produto));
                                        pItemNoCarrinho->codigo = pItem_inserir->codigo;
                                        strcpy(pItemNoCarrinho->descricao,pItem_inserir->descricao);
                                        pItemNoCarrinho->preco = pItem_inserir->preco;
                                        pItemNoCarrinho->qtd_estoque = qtd_desejada; 
                        			    aumentar_lista(carrinho,indice_ult_produto_carrinho);
                                        (*carrinho)[*indice_ult_produto_carrinho] = pItemNoCarrinho;
                                        printf("\n\n--------------------------------------------------------- ");
                                        printf("\n'%s' adicionado ao carrinho com sucesso!!!",pItemNoCarrinho->descricao);
                                        printf("\n-----------------------------------------------------------\n");
                                        system("PAUSE");
                              }
                          }

                   //cluir_item(estoque,indice_ult_produto,cod_excluir);
                
                        printf("\n\nIncluir novo Produto?\nDigite: I para inserir novo item (qualquer tecla interrompe a inclusao) -> ");
                        scanf(" %c",&again);
                        limparBuffer();
                    }else{
                          getch();
                          }
                }while(again == 'I' || again == 'i' );				
				sair = 0;
				break;
			case 2:
				system("CLS");
                printf("\n##################################");
				printf("\nRelacao de produtos no carrinho");
				printf("\n#################################\n");
				exibir_produtos_estoque(*carrinho,*indice_ult_produto_carrinho,1);
                sair = 0;
				getch();
				break;								
			case 3:
				system("CLS");
                printf("\n##################################");
				printf("\nExcluir produto do carrinho");
				printf("\n#################################\n");
				exibir_produtos_estoque(*carrinho,*indice_ult_produto_carrinho,1);
				PProduto pItem_excluir = menu_escolha_item(*carrinho,*indice_ult_produto_carrinho,"DIGITAR CODIGO QUE DESEJA EXCLUIR: ","CARRINHO");
                if (pItem_excluir){
                   system("CLS");
                   printf("\n#########################################################");
    			   printf("\nRemovendo produto '%s' do carrinho",pItem_excluir->descricao);
    			   printf("\n#########################################################\n");
                   
                   excluir_item(carrinho,indice_ult_produto_carrinho,pItem_excluir->codigo);
                }else{
                      getch();
                      }
				sair = 0;
				break;
			case 4:
                 char opcao = 'x';
                 
                 do{
                    	system("CLS");
                        printf("\n#################################################");
        				printf("\nAlterar quantidade do produto do carrinho");
        				printf("\n#################################################\n");
        				exibir_produtos_estoque(*carrinho,*indice_ult_produto_carrinho,1);
        				PProduto pItem_alterar_quantidade = menu_escolha_item(*carrinho,*indice_ult_produto_carrinho,"DIGITAR CODIGO QUE DESEJA ALTERAR A QUANTIDADE: ","CARRINHO");
        				if (pItem_alterar_quantidade){
                           PProduto pItemEstoque = NULL;
                           codigo_existe(*estoque,*indice_ult_produto_estoque,pItem_alterar_quantidade->codigo,&pItemEstoque);
                                                                                                                                   
                           int nova_qtd = perguntar_quantidade(pItemEstoque,pItem_alterar_quantidade->qtd_estoque);
                           if(nova_qtd == 0){
                                       excluir_item(carrinho,indice_ult_produto_carrinho,pItem_alterar_quantidade->codigo);
                                       printf("Quantidade '0' item excluido do carrinho com sucesso!!");
                                       }
                           else{ 
                                       pItem_alterar_quantidade->qtd_estoque = nova_qtd;
                                       printf("Quantidade alterada com sucesso!!");
                           }
                           printf("\n-------------------------------------");
                           printf("\nContinuar?\n Digite 's' para continuar alterando as quantidades.");
                           
                            scanf(" %c",&opcao);
                            limparBuffer();
                            
                           }else{
                                 getch();
                                 }
                   }while(opcao == 's' || opcao == 'S');					
				//getch();
				sair = 0;
				break;
			case 5:
                system("CLS");
			    if(*indice_ult_produto_carrinho < 0){
                     printf("\n ---------------------------------------------");
                     printf("\nNENHUM ITEM NO CARRINHO CADASTRE ALGUM ITEM.");
                     printf("\n ---------------------------------------------");
                }else{
    				srand(time(0));
    				int Pedido = rand();
    				printf("\n- Numero do pedido %d gerado;",Pedido);
    				atualizar_estoque(*estoque,*indice_ult_produto_estoque,*carrinho,*indice_ult_produto_carrinho);
    				printf("\n- Estoque atualizado;");
    			
    				aumentar_lista_pedidos(pedidos,indice_ult_pedido_finalizado);//(vetor n�o alocado, -1)
    			
    				printf("\n- Tamanho da lista de pedidos atualizada;");
    				(*pedidos)[*indice_ult_pedido_finalizado]->numero_pedido = Pedido;
    				int i;
    				
    
   			
   				   PPProduto produtos_do_pedido = (PPProduto)malloc((*indice_ult_produto_carrinho+2) * sizeof(PProduto));
   				   if(!produtos_do_pedido){ 
                            	printf("PROBLEMA NA ALOCA��O DO PRODUTO\n\n");
                            	system("PAUSE");
                        	}
                    (*pedidos)[*indice_ult_pedido_finalizado]->produtos = (PPProduto)malloc((*indice_ult_produto_carrinho+2) * sizeof(PProduto));
   				    (*pedidos)[*indice_ult_pedido_finalizado]->indice_ult_produto_pedido = *indice_ult_produto_carrinho;
    				for(i=0;i<=*indice_ult_produto_carrinho;i++){
                           //aumentar_lista(plista_produtos_pedido_atual,pindice_ult_produto_pedido_finalizado_atual);
                           printf("\n-(%d) %d %s vendido(s);",(*carrinho)[i]->codigo,(*carrinho)[i]->qtd_estoque,(*carrinho)[i]->descricao);
                         
                           PProduto produto_vendido = (PProduto) malloc(sizeof(Produto));
                           //PProduto produto = (PProduto) malloc(sizeof(Produto));
                           if(!produto_vendido){ 
                            	printf("PROBLEMA NA ALOCA��O DO PRODUTO\n\n");
                            	system("PAUSE");
                        	}
       		               produto_vendido->codigo = (*carrinho)[i]->codigo;
                           strcpy(produto_vendido->descricao,(*carrinho)[i]->descricao);
                           produto_vendido->preco = (*carrinho)[i]->preco;
                           produto_vendido->qtd_estoque = (*carrinho)[i]->qtd_estoque;
                           (*pedidos)[*indice_ult_pedido_finalizado]->produtos[i] = produto_vendido;
                    }
    				printf("\n- Produtos processados;");
    				
    				limpar_carrinho(carrinho,indice_ult_produto_carrinho);
    				
    				printf("\n- Carrinho esvaziado;");
    	
    				
    			printf("\nPedido finalizado com sucesso!!!!");	
                }
				getch();
				sair = 0;
				break;								
			case 6:
                system("CLS");
                	if(*indice_ult_produto_carrinho < 0){
                         printf("\n ---------------------------------------------");
                         printf("\nNENHUM ITEM NO CARRINHO CADASTRE ALGUM ITEM.");
                         printf("\n ---------------------------------------------");
                }else{
        				printf("Carrinho foi apagado com sucesso!");
        				limpar_carrinho(carrinho,indice_ult_produto_carrinho);
            }
				getch();
				sair = 0;
				break;								
			case 7:
				//printf("Voltar");
				sair = 1;
				break;
			default:
				printf("Opcao Invalida!");
				getch();
				sair = 0;			
		}
	}while(!sair);
	
}

void gerenciar_menu_principal(Loja* pLoja){
	int opcao;
	int sair = 0;	
	
	do{	
		opcao = menu_principal_opcoes();		
		switch(opcao){
			case 1:				
				gerenciar_menu_produto(pLoja);
				//getch();
				break;
			case 2:			
				gerenciar_menu_pedido(pLoja);
				//
				break;
            case 3:
                 system("CLS");
                 if(pLoja->indice_ult_produto_estoque >=0){ 
                                               limpar_carrinho(&pLoja->estoque,&pLoja->indice_ult_produto_estoque);
                                               printf("\nProdutos apagados!");
                 }
                 if(pLoja->indice_ult_produto_carrinho >=0){
                                                limpar_carrinho(&pLoja->carrinho,&pLoja->indice_ult_produto_carrinho);
				                                printf("\nPedidos apagados!");
                 }
                 printf("\nLoja zerada por completo!");
                 getch();
				 sair = 0;
				break;								
			case 4:
				printf("Sair");
				sair = 1;
				break;
			default:
				printf("Opcao Invalida!");
				getch();
				sair = 0;			
		}
	}while(!sair);
	
}

int main(int argc, char *argv[]) {
    Loja minhaLoja;
    minhaLoja.indice_ult_produto_estoque = -1;
    minhaLoja.indice_ult_produto_carrinho = -1;
    minhaLoja.indice_ult_pedido_finalizado = -1;
    //PPProduto estoque;
    //PPProduto carrinho;
    //PPPedido pedidos_finalizados;
    //int indice_ult_produto_estoque = -1;
    //int indice_ult_produto_carrinho = -1;
    //int indice_ult_pedido_finalizado = -1;
	gerenciar_menu_principal(&minhaLoja);	
	return 0;
}
