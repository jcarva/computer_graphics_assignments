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

A implementação deste Pipeline Gráficose dá por meio de quatro componentes principais que são listados abaixo.

* Simulador de acesso a memória de video e [rasterizador de primitivas](https://github.com/jcarva/computer_graphics_assignments/tree/master/rasterization) desenvolvido na primeira avaliação prática da disciplina.

* Leitor de arquivos com extesão .obj que recupera os vertices do objeto a que será renderizado. Tal componente foi disponibilizado pelo Prof. Christian Pagot simultaneamente com a definição e especificações do projeto.

* Classe que dá suporte a criação e operações com matrizes

* Funções de transformações geometricas e operações contidas em um pipeline gráfico.

### [Matrix](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h)

As operações básicas necessarias com matrizes para a construção de um pipeline gráfico foram implementadas por meio da classe [Matrix](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h), assim como a construção e representação de matrizes e vetores. Abaixo estão listados e descritos os metodos e operações estão implementados na classe [Matrix](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h) e suas implementações verificadas no [link](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h).

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

### [Graphic Pipeline](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)

As transformações geometricas e operações para o funcionamento de um pipeline gráfico foram implementados no header [graphic_pipeline.h](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h). Abaixo estão listadas e descritas(quando necessario) as funções contidas no header [graphic_pipeline.h](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h) e suas implementações verificadas no [link]((https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)).

#### [void Scale(double x_scale_factor, double y_scale_factor, double z_scale_factor)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)

#### [void Translation(double x_displacement, double y_displacement, double z_displacement)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)

#### [void Rotation(double x_axis, double y_axis, double z_axis, double angle)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)

#### [double CrossProduct(Vector * v1, Vector * v2, Vector * product)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)

#### [double VectorNorm(Vector * vector)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)

#### [void LookAt(vector\<double> cam_position, vector\<double> look_at, vector<double> up)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)

#### [void ViewPlaneDistance(double z_distance)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)

#### [void ViewPort(int initial_x, int initial_y, int width, int height)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)

#### [void PipelineLoader()](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)

#### [Pixel Pipeline(double x, double y, double z)](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/graphic_pipeline.h)

### [Main e Renderização](https://github.com/jcarva/computer_graphics_assignments/blob/master/graphic_pipeline/project/matrix.h)