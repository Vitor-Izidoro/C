Programação Imperativa – Trabalho 2
Prof. Alcides Calsavara
Estrutura geral da aplicação:
A aplicação deve ser composta por três (3) programas na linguagem C, a saber:
1. Gerador:
	o Lê dados de um arquivo texto
	o Armazena internamente esses dados em memória heap
	o Grava esses dados em um arquivo binário
2. Editor:
	o Lê dados do arquivo binário
	o Armazena internamente esses dados em memória heap
	o Realiza operações sobre esses dados
	o Gera um novo arquivo binário contendo os dados atualizados
	A geração do arquivo binário pode ocorrer a qualquer momento da
	execução do Editor (a pedido do usuário), bem como no final da
	execução (obrigatoriamente, desde que os dados em memória tenham
	sido atualizados desde a última geração do arquivo binário.)
3. Exportador:
	o Lê dados do arquivo binário
	o Gera um arquivo texto contendo os dados, no mesmo formato do
	arquivo lido pelo Gerador.
	Requisitos de implementação:
1. Sobre os dados:
	a. Podem se referir a qualquer coisa, à escolha de cada equipe de
	estudantes. Por exemplo, os dados podem se referir a pessoas ou a
	veículos.
	b. Devem corresponder a uma sequência de elementos, sendo que,
	para cada elemento, devem existir, ao menos, dois campos. Por
	exemplo, se os dados correspondem a uma sequência de pessoas,
	pode haver, para cada uma delas, o seu nome e o seu CPF.
	c. Um dos campos dos elementos deve ser uma chave única de
	identificação. No exemplo acima, o CPF seria o campo chave de
	identificação única de um elemento.
2. Sobre o armazenamento dos dados em memória heap, tanto no Gerador
quanto no Editor:
	a. Deve ser feito por meio de uma lista encadeada que fique o tempo
	todo ordenada crescentemente com relação ao campo chave dos
	elementos.
	b. No Gerador, a lista deve conter, ao menos, 20 elementos.
	c. No Gerador, os dados lidos do arquivo texto estão em ordem
	aleatória com relação ao campo chave dos elementos.
3. Sobre o Editor:
	a. Deve interagir com o usuário para permitir a escolha de uma
	operação, fazendo as devidas verificações para consistência dos
	dados fornecidos pelo usuário. Essa interação deve ser contínua, até
	que o usuário escolha a opção de encerramento do programa.
	b. Deve dar opção ao usuário de inserir novos dados, fazendo com que
	a lista encadeada aumente. Essa inserção pode ocorrer em qualquer
	ponto da lista, dependendo do campo chave do elemento inserido.
	c. Deve dar opção ao usuário de remover dados, fazendo que a lista
	encadeada diminua. Essa remoção pode ocorrer em qualquer ponto
	da lista, dependendo do campo chave do elemento removido.
	d. Deve dar opção ao usuário de exibir os dados de um elemento
	específico da lista de acordo com uma chave de busca fornecida pelo
	usuário.
4. Sobre os arquivos texto e binário:
	a. Os seus nomes devem ser fornecidos aos programas como
	parâmetros de execução (argc e argv).
	b. Devem ser feitas todas as verificações necessárias sobre o sucesso da
	operação de abertura de arquivo.
	c. No arquivo texto, não pode haver informação explícita sobre a
	quantidade de dados, ou seja, a leitura deve, necessariamente,
	detectar o fim do arquivo.
5. Sobre a codificação:
	a. Deve haver, no mínimo, uma função cujo retorno seja um ponteiro.
	b. Deve haver, no mínimo, uma função recursiva. Por exemplo, a função
	de busca na lista para exibir os dados de um elemento específico.
	c. Deve respeitar todas as boas práticas de codificação estudadas no
	TDE 2.
6. Sobre a organização do código:
	a. Deve ser estruturado em funções relativamente pequenas.
	b. Deve ser organizado em arquivos de implementação (arquivo .c) e
	arquivos cabeçalho (arquivo .h).


/////////////////////////////////////////////////////////////////////////////
	REQUISITOS 
	1. Relacione a lista de arquivos que compõem o código fonte da aplicação.
2. Para cada arquivo fonte de implementação (normalmente, com extensão .c), descreva
o seu conteúdo em apenas uma sentença. Por exemplo, “o arquivo List.c contém a
implementação de todas as funções que manipulam a lista de itens em memória
heap”.
3. Transcreva aqui o código contido em um arquivo cabeçalho (.h) que compõe a
aplicação.
4. Liste todas as relações de inclusão entre dois arquivos. Por exemplo, “o arquivo Editor.c
inclui o arquivo Lista.h”.
5. Transcreva aqui o código do struct usado no programa para representar os itens de
dados e indique qual dos campos é a chave única de identificação.
6. Os itens de dados lidos pelo programa Gerador são armazenados em uma lista na
memória heap?
7. O programa Gerador libera toda a memória alocada dinamicamente (heap)?
8. Os itens de dados lidos pelo programa Editor são armazenados em uma lista na
memória heap?
9. O programa Editor libera toda a memória alocada dinamicamente (heap)?
10. Relacione a lista de funções que manipulam a lista de itens em memória heap e, para
cada função, faça uma descrição o que faz a função em apenas uma sentença.
11. Transcreva aqui o código de uma função presente na aplicação que retorna um
ponteiro? Explique o que significa o ponteiro retornado pela função.
12. Transcreva aqui o código de uma função recursiva presente na aplicação.
13. As funções possuem tamanho relativamente pequeno?
14. O arquivo de entrada para o Gerador contém dados em ordem aleatória com respeito
ao campo que é a chave única de identificação?
15. O programa Gerador lê dados do arquivo texto de entrada até encontrar o fim do
arquivo?
16. O programa Gerador faz consistência dos dados contidos no arquivo de entrada
sempre que for necessário? Por exemplo, ao ler um dado numérico, o programa
verifica se, de fato, o arquivo contém um número naquele ponto?
17. O programa Editor lê dados do arquivo binário de entrada até encontrar o fim do
arquivo?
18. No Editor, a operação para inserir um novo item na lista faz essa inserção de modo que
a lista permaneça em ordem crescente com respeito ao campo que é a chave única de
identificação?
19. No Editor, a operação para inserir um novo item na lista faz essa inserção corretamente
quando o novo item passa a ser o primeiro da lista?
20. No Editor, a operação para inserir um novo item na lista faz essa inserção corretamente
quando o novo item passa a ser o último da lista?
21. No Editor, a operação para inserir um novo item na lista faz essa inserção corretamente
quando o novo item não deve ser o primeiro nem o último da lista?
22. No Editor, a operação para remover um item na lista faz essa remoção de modo que a
lista permanece em ordem crescente com respeito ao campo que é a chave única de
identificação?
23. No Editor, a operação para remover um novo item na lista faz essa remoção
corretamente quando o item removido é o primeiro da lista?
24. No Editor, a operação para remover um novo item na lista faz essa remoção
corretamente quando o item removido é o último da lista?
25. No Editor, a operação para remover um item na lista faz essa remoção corretamente
quando o item removido não é o primeiro nem o último da lista?
26. No Editor, a operação para exibir os dados de um item específico (de acordo com uma
chave fornecida pelo usuário) faz essa exibição corretamente quando esse item é o
primeiro da lista?
27. No Editor, a operação para exibir os dados de um item específico (de acordo com uma
chave fornecida pelo usuário) faz essa exibição corretamente quando esse item é o
último da lista?
28. No Editor, a operação para exibir os dados de um item específico (de acordo com uma
chave fornecida pelo usuário) faz essa exibição corretamente quando esse item não é o
primeiro nem o último da lista?
29. A execução do Exportador depois de uma sessão do Editor gera um arquivo texto cujos
dados refletem corretamente todas as operações realizadas na sessão?
30. O nome do arquivo de entrada do Gerador é fornecido como um argumento do
programa?
31. Os nomes dos arquivos de entrada e de saída do Exportador são fornecidos como
argumentos do programa?
32. O nome do arquivo de entrada e saída do Editor é fornecido como um argumento do
programa?
33. Os nomes de variáveis e funções estão bem adequados aos seus propósitos no código?
34. As constantes presentes no código são, de fato, declaradas como constantes (usando
#define ou const)?
35. O código fonte está bem documentado por meio de comentários?