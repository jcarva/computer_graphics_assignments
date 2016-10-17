# Pipeline Gráfico

---

## Introdução

Esta postagem é parte obrigatoria da segunda avaliação prática da disciplina de Introdução à Computação Gráfica, ministrada pelo Prof. Christian Pagot no semestre letivo 2016.1.

As definições e especificações projeto podem ser acessadas através deste [link](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project_definition.pdf).

Como explanado em sala de aula pelo Prof. Christian Pagot, qualquer conteúdo teórico extra-atividade não obrigatóriamente precisa ser descrito na postagem.

Todo o código citado está disponivel neste [repositorio público](https://github.com/jcarva/computer_graphics_assignments/tree/master/graphic_pipeline) e acessivel também para [download direto](https://github.com/jcarva/computer_graphics_assignments/archive/master.zip).

Caso o código ou a corrente postagem seja de alguma ajuda peço para que contribua com seu [Star](https://github.com/jcarva/computer_graphics_assignments) no repositorio do projeto.


**Tem alguma questão ou sugestão?**																												
Contate-me no [Linkedin](https://www.linkedin.com/in/jaelson-carvalho-4b84a3a2?trk=nav_responsive_tab_profile_pic), envie um email para jaelsoncarvalhojr@gmail.com, ou crie um pull request neste projeto. Toda ajuda e qualquer é bem vinda.

---

## Implementação

A implementação deste Pipeline Gráfico se dá por meio de quatro componentes principais que são listados abaixo.

* Simulador de acesso a memória de video e [rasterizador de primitivas](https://github.com/jcarva/computer_graphics_assignments/tree/master/rasterization) desenvolvido na primeira avaliação prática da disciplina.

* Leitor de arquivos com extesão .obj que recupera os vertices do objeto a que será renderizado. Tal componente foi disponibilizado pelo Prof. Christian Pagot simultaneamente com a definição e especificações do projeto.

* Classe que dá suporte a criação e operações com matrizes

* Header que contem funções de transformações geometricas e operações contidas em um pipeline gráfico.

### Matrix

As operações básicas necessarias com matrizes para a construção de um pipeline gráfico foram implementadas por meio da classe [Matrix](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h), assim como a construção e representação de matrizes e vetores. Abaixo estão listados e descritos os metodos e operações implementadas na classe [Matrix](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h) e suas implementações verificadas no [link](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h).

#### [Matrix()](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h)

#### [Matrix(int num_rows, int num_columns)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h)

#### [~Matrix()](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h)

#### [void SetMatrix(vector\<double> values)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h)

#### [vector\<int> GetDimensions()](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h)

#### [void SetValue(int row, int column, double value)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h)

#### [double GetValue(int row, int column)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h)

#### [void LoadIdentityMatrix()](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h)

#### [void MatrixMultiplication(Matrix& m1, Matrix& m2)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h)

#### [void DivisionByScalar(Matrix& m, double scalar)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h)

#### [void Display()](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h)

### Graphic Pipeline

As transformações geometricas e operações para o funcionamento de um pipeline gráfico foram implementados no header [graphic_pipeline.h](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h). Abaixo estão listadas e descritas(quando necessario) as funções contidas no header [graphic_pipeline.h](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h) e suas implementações verificadas no [link]((https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)).

#### [void Scale(double x_scale_factor, double y_scale_factor, double z_scale_factor)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)

#### [void Translation(double x_displacement, double y_displacement, double z_displacement)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)

#### [void Rotation(double x_axis, double y_axis, double z_axis, double angle)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)

#### [double CrossProduct(Vector * v1, Vector * v2, Vector * product)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)

#### [double VectorNorm(Vector * vector)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)

#### [void LookAt(vector\<double> cam_position, vector\<double> look_at, vector\<double> up)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)

#### [void ViewPlaneDistance(double z_distance)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)

#### [void ViewPort(int initial_x, int initial_y, int width, int height)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)

#### [void PipelineLoader()](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)

#### [Pixel Pipeline(double x, double y, double z)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)

### Main e Renderização

#### Setup

##### Experimento 1

##### Experimento 2

##### Experimento 3

##### Experimento 4

##### Experimento 5

---

## Dificuldades

* Encontrar a melhor maneira para a generalização do algoritimo de rasterização foi a parte mais árdua de todo o projeto, levando a maior parte do tempo de desenvolvimento.

---

## Possiveis trabalhos futuros

* Assim como o atributo ```buffer_line``` nos objetos da classe ```Line```,  o incremento de cor para o próximo ponto na interpolação de cores também poderia se tornar variavel de instancia da classe. Assim evitando calcular novamente quando feito o preenchimento de triângulos.

---

## Conclusão

Com este trabalho pude entender bem o funcionamento de uma rasterização, fixando os conceitos iniciais de computação gráfica de uma maneira pratica. Estudar uma melhor de maneira de implementar o algoritmo me trouxe uma visão mais ampla sobre como eu posso manipular objetos em espaços gráficos.

---

## Referências

* [Bjarne Stroustrup's C++ Style and Technique FAQ](http://www.stroustrup.com/bs_faq2.html)

* [Bresenham's line algorithm - Wikipedia](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm)

* [Matrizes de Reflexão](http://wiki.ued.ipleiria.pt/wikiEngenharia/index.php/Matriz_de_reflex%C3%A3o)

* Notas de Aula do Prof. Christian Pagot

* [Shapari - Reflexão em torno da reta y = x](http://www.ufrgs.br/espmat/disciplinas/tutoriais_softwares/shapari/shapari_rfxy.htm)

* [The Bresenham Line-Drawing Algorithm - Department of Computer Science, University of Helsinki](https://www.cs.helsinki.fi/group/goa/mallinnus/lines/bresenh.html)