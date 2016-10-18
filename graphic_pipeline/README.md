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

As operações básicas necessarias com matrizes para a construção de um pipeline gráfico foram implementadas por meio da classe [Matrix](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h), assim como a construção e representação de matrizes e vetores. Abaixo estão listados e descritos os metodos e operações implementadas na classe [Matrix](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h) e suas implementações verificadas no [link](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h) ou em clickando cada método.

#### [Matrix()](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h)
Construtor padrão que inicializa uma matriz quadratica de dimensões 3x3.
 
 
#### [Matrix(int num_rows, int num_columns)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h)
Contrutor que recebe como argumentos as dimensões da matriz que será criada.


#### [~Matrix()](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h)
Destrutor que desaloca memoria de uma matriz previamente criada.


#### [void SetMatrix(vector\<double> values)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h)
Método que recebe como argumento um conjunto de valores e os atribui para a matriz.


#### [vector\<int> GetDimensions()](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h)
Método que retorna um conjunto de valores com as dimensões da matriz.


#### [void SetValue(int row, int column, double value)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h)
Método que recebe como argumentos uma posição especifica na matriz e o valor que será atribuido a tal posição.


#### [double GetValue(int row, int column)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h)
Método que recebe como argumentos uma posição especifica na matriz e retorna o valor que está atribuido a tal posição.


#### [void LoadIdentityMatrix()](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h)
Método que converte a matriz em uma matriz identidade. 


#### [void MatrixMultiplication(Matrix& m1, Matrix& m2)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h)
Método que recebe como argumentos duas referências de matrizes, realiza a operação de multiplicação de matrizes e atribui o resultado a matriz previamente criada.


#### [void DivisionByScalar(Matrix& m, double scalar)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h)
Método que recebe como argumento uma referência de matriz e um escalar, realiza a operação de divisão em todos os elementos da matriz usando o argumento escalar como divisor, e atribui o resultado a matriz previamente criada.


#### [void Display()](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h)
Método que exibe os correntes valores da matriz.


### Graphic Pipeline

As transformações geometricas e operações para o funcionamento de um pipeline gráfico foram implementados no header [graphic_pipeline.h](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h). Abaixo estão listadas e descritas(quando necessario) as funções contidas no header [graphic_pipeline.h](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h) e suas implementações verificadas no [link]((https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)) ou em clickando cada função.

#### [Máquina de Estados](http://stackoverflow.com/questions/31282678/what-is-the-opengl-state-machine)
Seguindo o padrão do OpenGL(Open Graphics Library), a implementação deste pipeline gráfico será feita de forma que funcione como uma [máquina de estados](http://stackoverflow.com/questions/31282678/what-is-the-opengl-state-machine). Logo torna-se necessario a existencia de dados persistentes em tempo de execução. Esses dados são as matrizes Model, View, Projection e Viewport.
``` c++
Matrix model(4, 4);
Matrix view(4, 4);
Matrix projection(4, 4);
Matrix viewport(4, 4);
```


#### Vector
O tipo vetor que é utilizado em algumas etapas do pipelipe gráfico é criado com o construtor padrão da classe Matrix, ou seja, possui dimensões 3x3.
``` c++
typedef Matrix Vector;
```




Na primeira etapa do pipeline gráfico as transformações são aplicadas somente na matriz Model. Tais tranformações são acumulativas, podem ser agredadas em uma única matriz e verificadas a seguir.  




#### [void Scale(double x_scale_factor, double y_scale_factor, double z_scale_factor)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)
Transformação geometrica de escala que modifica a matriz model.
``` c++
void Scale(double x_scale_factor, double y_scale_factor, double z_scale_factor)
{
    Matrix scale_matrix(4, 4);

    scale_matrix.LoadIdentityMatrix();

    scale_matrix.SetValue(0, 0, x_scale_factor);
    scale_matrix.SetValue(1, 1, y_scale_factor);
    scale_matrix.SetValue(2, 2, z_scale_factor);

    model.MatrixMultiplication(model, scale_matrix);

    model.Display(); // Just to log

}
```




#### [void Translation(double x_displacement, double y_displacement, double z_displacement)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)
Transformação geometrica de translação que modifica a matriz model.
``` c++
void Translation(double x_displacement, double y_displacement, double z_displacement)
{
    Matrix translation_matrix(4, 4);

    translation_matrix.LoadIdentityMatrix();

    translation_matrix.SetValue(0, 3, x_displacement);
    translation_matrix.SetValue(1, 3, y_displacement);
    translation_matrix.SetValue(2, 3, z_displacement);

    model.MatrixMultiplication(model, translation_matrix);

    model.Display(); // Just to log

}
```




#### [void Rotation(double x_axis, double y_axis, double z_axis, double angle)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)
Transformação geometrica de rotação que modifica a matriz model.
``` c++
void Rotation(double x_axis, double y_axis, double z_axis, double angle)
{
    Matrix rotation_matrix(4, 4);

    rotation_matrix.LoadIdentityMatrix();

    if(x_axis > 0.0)
    {
        rotation_matrix.SetValue(1, 1, cos(angle));
        rotation_matrix.SetValue(1, 2, -sin(angle));
        rotation_matrix.SetValue(2, 1, sin(angle));
        rotation_matrix.SetValue(2, 2, cos(angle));
    }

    if(y_axis > 0.0)
    {
        rotation_matrix.SetValue(0, 0, cos(angle));
        rotation_matrix.SetValue(0, 2, sin(angle));
        rotation_matrix.SetValue(2, 0, -sin(angle));
        rotation_matrix.SetValue(2, 2, cos(angle));
    }

    if(z_axis > 0.0)
    {
        rotation_matrix.SetValue(0, 0, cos(angle));
        rotation_matrix.SetValue(0, 1, -sin(angle));
        rotation_matrix.SetValue(1, 0, sin(angle));
        rotation_matrix.SetValue(1, 1, cos(angle));
    }

    model.MatrixMultiplication(model, rotation_matrix);

    model.Display(); // Just to log
}
```




Na segunda etapa do pipeline gráfico as operações são aplicadas na matriz View. 




#### [void LookAt(vector\<double> cam_position, vector\<double> look_at, vector\<double> up)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)
Função de definição da camera e construção da matrix View a partir dos dados câmera
``` c++
void LookAt(vector<double> cam_position, vector<double> look_at, vector<double> up)
{
    Vector x_cam(3, 1);
    Vector y_cam(3, 1);
    Vector z_cam(3, 1);

    Matrix Bt(4, 4);
    Matrix T(4, 4);

    Vector Looked(3, 1);
    Vector Up(3, 1);

    Looked.SetMatrix({cam_position[0] - look_at[0], cam_position[1] - look_at[1], cam_position[2] - look_at[2]});
    Up.SetMatrix(up);

    z_cam.DivisionByScalar(Looked, VectorNorm(&Looked));

    CrossProduct(&Up, &z_cam, &Looked);

    x_cam.DivisionByScalar(Looked, VectorNorm(&Looked));

    CrossProduct(&z_cam, &x_cam, &Looked);

    y_cam.DivisionByScalar(Looked, VectorNorm(&Looked));

    vector<double> Bt_values {
            x_cam.GetValue(0, 0), x_cam.GetValue(1, 0), x_cam.GetValue(2, 0), 0,
            y_cam.GetValue(0, 0), y_cam.GetValue(1, 0), y_cam.GetValue(2, 0), 0,
            z_cam.GetValue(0, 0), z_cam.GetValue(1, 0), z_cam.GetValue(2, 0), 0,
            0,                    0,                    0,            1
    };

    Bt.SetMatrix(Bt_values);

    T.LoadIdentityMatrix();
    T.SetValue(0, 3, -cam_position[0]);
    T.SetValue(1, 3, -cam_position[1]);
    T.SetValue(2, 3, -cam_position[2]);

    view.LoadIdentityMatrix();

    view.MatrixMultiplication(Bt, T);

    view.Display(); // Just to log
}
```




Na terceira etapa do pipeline gráfico as operações são aplicadas na matriz Projection. 




#### [void ViewPlaneDistance(double z_distance)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)
Função de contrução da matrix Projection a partir a definição da distancia ```Z``` até o view plane.
``` c++
void ViewPlaneDistance(double z_distance)
{
    projection.SetValue(2, 3, z_distance);
    projection.SetValue(3, 2, (-1) / z_distance);
    projection.SetValue(3, 3, 0);

    projection.Display(); // Just to log
}
```




Na quarta etapa do pipeline gráfico as operações são aplicadas na matriz Viewport. 




#### [void ViewPort(int initial_x, int initial_y, int width, int height)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)
Função de contrução da matriz Viewport a partir das dimensões da janela de projeção.
``` c++
void ViewPort(int initial_x, int initial_y, int width, int height)
{
    Matrix S1(4, 4);
    Matrix S2(4, 4);
    Matrix T(4, 4);

    S1.LoadIdentityMatrix();
    S2.LoadIdentityMatrix();
    T.LoadIdentityMatrix();

    S1.SetValue(1, 1, -1);

    S2.SetValue(0, 0, (width - 1) / 2.0f);
    S2.SetValue(1, 1, (height - 1) / 2.0f);

    T.SetValue(0, 3, 1);
    T.SetValue(1, 3, 1);

    viewport.LoadIdentityMatrix();

    viewport.MatrixMultiplication(T, S1);
    viewport.MatrixMultiplication(S2, viewport);

    viewport.Display(); // Just to log
}
```




Sabendo que a implementação do pipeline gráfico segue o padrão do OpenGL, ou seja, se comporta como uma maquina de estados, é necessario a existencia de um estado inicial.




#### [void PipelineLoader()](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)
Função de carregamento de estado inicial do pipeline gráfico.
``` c++
void PipelineLoader()
{
    model.LoadIdentityMatrix();
    view.LoadIdentityMatrix();
    projection.LoadIdentityMatrix();
    viewport.LoadIdentityMatrix();
    ViewPlaneDistance(1);
}
```




Calculos de produtos vetoriais e norma de vetores são necessarios em um pipeline gráfico.




#### [double CrossProduct(Vector * v1, Vector * v2, Vector * product)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)
Função de calculo de produto vetorial que é utilizada em algumas etapas do pipelipe gráfico.
``` c++
double CrossProduct(Vector * v1, Vector * v2, Vector * product)
{
    (*product).SetValue(0, 0, (*v1).GetValue(1,0) * (*v2).GetValue(2, 0) - (*v2).GetValue(1, 0) * (*v1).GetValue(2,0));
    (*product).SetValue(1, 0, (*v1).GetValue(2,0) * (*v2).GetValue(0, 0) - (*v2).GetValue(2, 0) * (*v1).GetValue(0,0));
    (*product).SetValue(2, 0, (*v1).GetValue(0,0) * (*v2).GetValue(1, 0) - (*v2).GetValue(0, 0) * (*v1).GetValue(1,0));
}
```




#### [double VectorNorm(Vector * vector)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)
Função de calculo de modulo de vetor que é utilizada em algumas etapas do pipelipe gráfico.
``` c++
double VectorNorm(Vector * vector)
{
    return sqrt (
            (*vector).GetValue(0, 0) * (*vector).GetValue(0, 0) +
            (*vector).GetValue(1, 0) * (*vector).GetValue(1, 0) +
            (*vector).GetValue(2, 0) * (*vector).GetValue(2, 0)
    );
}
```




Posteriormente a implementação e configuração de funções necessárias em um pipeline gráfico, resta agregarmos as mesmas em uma única função que é o Pipeline Gráfico propriamente dito.




#### [Pixel Pipeline(double x, double y, double z)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)
Função que recebe como argumento um vertice, realiza todas as operações do pipeline gráfico no mesmo e retorna tal vertice transformado.
``` c++
Pixel Pipeline(double x, double y, double z)
{
    vector<double> Vertex_values{x, y, z, 1};

    Matrix Vertex(4, 1);

    Vertex.SetMatrix(Vertex_values);

    Vertex.MatrixMultiplication(model, Vertex);
    Vertex.MatrixMultiplication(view, Vertex);
    Vertex.MatrixMultiplication(projection, Vertex);
    Vertex.DivisionByScalar(Vertex, Vertex.GetValue(3, 0));
    Vertex.MatrixMultiplication(viewport, Vertex);

    Pixel reference_pixel = Pixel(round(Vertex.GetValue(0, 0)), round(Vertex.GetValue(1, 0)));

    return reference_pixel;
}
```


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