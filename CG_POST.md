# Pipeline Gráfico: Rasterização de Primitivas

---

## Introdução

Esta postagem é parte obrigatoria da primeira avaliação prática da disciplina de Introdução à Computação Gráfica, ministrada pelo Prof. Christian Pagot no semestre letivo 2016.1.

As definições e especificações projeto podem ser acessadas através deste [link](https://github.com/jcarva/rasterization/blob/master/project_definition.pdf).

Como explanado em sala de aula pelo professor, o conteúdo teórico extra atividade não precisa ser novamente descrito na postagem.

Todo o código citado está disponivel neste [repositorio público](https://github.com/jcarva/rasterization) e acessivel para download direto. <a class="github-button" href="https://github.com/jcarva/rasterization/archive/master.zip" data-icon="octicon-cloud-download" aria-label="Download jcarva/rasterization on GitHub">Download</a>

As etapas do desenvolvimento do projeto estão divididas em branchs no repositorio.

Caso o código ou a corrente postagem seja de alguma ajuda peço para que contribua com <a class="github-button" href="https://github.com/jcarva/rasterization" data-icon="octicon-star" aria-label="Star jcarva/rasterization on GitHub">Star</a>

**Tem alguma questão ou sugestão?**																												
Contate-me no [Linkedin](https://www.linkedin.com/in/jaelson-carvalho-4b84a3a2?trk=nav_responsive_tab_profile_pic), envie um email para jaelsoncarvalhojr@gmail.com, ou crie um pull request neste projeto. Toda ajuda e qualquer é bem vinda.

---

## 1. Rasterização de Pontos
<br>
Rasterizar pontos é o trabalho de "escrever" tais pontos na memória de vídeo, especialmente no colorbuffer, e que como resultado obtemos uma representação deste ponto na tela, que geralmente podemos denomina-lo pixel. Assim como na descrição matemática, em nosso caso cada ponto é formado por duas coordenadas, x e y que demarcam sua posição no espaço ou tela. Todo ponto representado na tela possui um cor, que é a informação registrada na memória de vídeo.

Antes de dar continuidade com a rasterização de pontos propriamente dita, é necessario que saibamos como de fato o colorbuffer. Podemos defini-lo como uma estrutura com espaço de coordenadas unidimensional. Sabendo que os pontos representados na tela possuem coordenadas bidimensionais, é necessario um mapeamento 2D => 1D para que possamos ter consistencia ao armazenarmos todos os pontos a serem escritos no colorbuffer.

Tal mapeamento supracitado pode ser obtido através da função Offset, descrita abaixo.

``` c++
int Pixel::Offset(int column, int row)
{
	return (column  + row * IMAGE_WIDTH) * 4;
}
```
Onde o argumento ```column``` representa a coordenada 'x' do ponto em um espaço bidimensional, e o argumento ```row``` representa a coordenada 'y' do mesmo ponto.

O valor de retorno da função Offset corresponde a posição do primeiro dos 4 bytes que guardam a cor do pixel em relação ao endereço do ponteiro do colorbuffer.

Você pode estar pensando : "***Como assim 4 bytes para uma cor?***"

Em nosso sistema um cor RGBA cada byte representa a intensidade das cores primarias usadas, sendo o primeiro byte para a cor vermelha(Red-R), e dando sequencia com verde(Green-G), azul(Blue-B) e Alpha-A(usado para transparência) respectivamente.

Sabendo disso, agora temos conhecimento suficiente para desenvolver a primeira das funções obrigatorias descritas na [especificação do projeto](https://github.com/jcarva/rasterization/blob/master/project_definition.pdf), a função ***PutPixel***.

### PutPixel

``` c++
void Pixel::PutPixel(int x, int y, double RGBA[4])
{
	if ((x >= 0 && x <= IMAGE_WIDTH) && (y >= 0 && y <= IMAGE_HEIGHT))
	{
		offset = Offset(x, y);

		for (int i = 0; i < 4; i++)
		{
			FBptr[offset + i] = (int)RGBA[i];
		}
	}
	else
	{
		std::clog << "Invalid PutPixel Position : [ x:" << x << " , y:" << y << " ]" << std::endl;
	}
}
``` 

Com a função acima devidamente implementada já podemos obter os primeiros resultados na tela como mostra a imagem abaixo.

---

## 2. Rasterização de Retas

---

## 3. Interpolação de Cores
<br>

<p align="center">
  <img src ="./post_images/color_interpolation.png"/>
  <h5 align="center">Figura #</h5>
</p>

---

## 4. Desenho de Triângulos
<br>
Após concluir com exito a construção de linhas, e o processo de interpolação de cores através da mesma, temos ferramentas suficientes para a contrução de um triângulo, cumprindo o desenvolvimento da terceira função obrigatoria descrita na [especificação do projeto](https://github.com/jcarva/rasterization/blob/master/project_definition.pdf), a função ***DrawTriangle***.

A lógica conceitual da implementação dessa função é receber três pontos quaisquer com suas respectivas cores, que serão os vertices do triângulo, e em seguida desenhar linhas de ligações e entre os vertices, ou seja, as arestas.

### DrawTriangle
``` c++
void Triangle::DrawTriangle(Pixel vertex1, Pixel vertex2, Pixel vertex3, int color_vertex1[4], int color_vertex2[4], int color_vertex3[4])
{
	Line().DrawLine("", vertex1, vertex2, color_vertex1, color_vertex2);
	Line().DrawLine("", vertex2, vertex3, color_vertex2, color_vertex3);
	Line().DrawLine("", vertex3, vertex1, color_vertex3, color_vertex1);
}
```

O resultado da chamada da função pode ser visualizado abaixo.
<p align="center">
  <img src ="./post_images/draw_triangle.png"/>
  <h5 align="center">Figura #</h5>
</p>

---

## 5. Preenchimento de Triângulos
<br>
No inicio desta etapa do projeto, tal tarefa de preencher um triangulo me parecia um tanto difícil, porém após ler mais sobre o problema me veio em mente que este tipo de preenchimento nada mais é do que várias linhas agregagadas, tendo como referência um dos vertices do triângulo e variando o ponto final com suas respectivas mundanças de cores. ***"Hã?"***, ***"Como assim?"***, ***"Que pontos finais são esses?"***, ***"Como saber a mudança da cor?"***

Para um melhor entendimento vamos admitir a existência de um triângulo ABC. Este triângulo possui os vertices A(Xa, Ya), B(Xb, Yb), C(Xc, Yc), e assim como todo triângulo, existêm retas de ligações entre tais vertices, retas AB, BC, CA. Escolhendo o vertice A como referência inicial, e a reta BC como a refência final para o desenho das linhas agregadas, a solução para o problema se mostra quase concluída.

O que agora necessitamos é da reta BC e a cor incremental para cada pixel da mesma. Assim como citado na seção ***Interpolação de Cores***, todo objeto linha, possui o atributo público ```buffer_line``` que armazena todos os pontos de tal linha, ou seja, basta criar a linha com ponto inicial B, final C e obtemos a reta BC com todos os pixels finais de cada linha de preenchimento.

``` c++
std::vector<Pixel> buffer_line;
```
O dado que nos falta é saber qual é a cor de cada pixel final para o desenho da linha interpolada, onde usamos a mesta solução da seção ***Interpolação de Cores***.

Agora podemos aplicar a solução de preenchimento citada anteriormente, um simples laço que irá desenhar uma linha para cada ponto da reta BC, tendo como inicio o vértice A, e incrementando a cor a cada iteração. 

``` c++
for (int i = 0; i < reference_line.buffer_line.size() ; ++i)
{
	Line().DrawLine("", vertex1, reference_line.buffer_line[i], color_vertex1, final_color);

	reference_color[0] += dColor[0];
	reference_color[1] += dColor[1];
	reference_color[2] += dColor[2];
	reference_color[3] += dColor[3];

	final_color[0] = (int) reference_color[0];
	final_color[1] = (int) reference_color[1];
	final_color[2] = (int) reference_color[2];
	final_color[3] = (int) reference_color[3];
}
```

O resultado inicial que obtemos com o procedimento pode ser visualizado na imagem abaixo.

<p align="center">
  <img src ="./post_images/draw_filled_triangle.png" />
  <h5 align="center">Figura #</h5>
</p>

Podemos notar que existem alguns pontos de falha no preenchimento inicial, a explicação para isso é a repetição de alguns pixels de preenchimento em diferentes linhas, onde a consequência é a não rasterização de alguns outros, ou seja, os pontos de falhas. Isso ocorre devido a escolha feita pelo algoritimo de Bresenham para a rasterização do próximo ponto, onde tais pontos algumas vezes coincidem na rasterização de linhas distintas.

O problema citado no paragrafo anterior pode ser simplesmente resolvido com a criação da função ```FilledTriangle```, que executa o procedimento de preenchimento fazendo permutações entre os vertices do triângulo, cambiando o ponto referência inicial e a reta com os pontos finais.

``` c++
void Triangle::FilledTriangle(Pixel vertex1, Pixel vertex2, Pixel vertex3, int color_vertex1[4], int color_vertex2[4], int color_vertex3[4])
{
	DrawFilledTriangle(vertex1, vertex2, vertex3, color_vertex1, color_vertex2, color_vertex3);
	DrawFilledTriangle(vertex3, vertex1, vertex2, color_vertex3, color_vertex1, color_vertex2);
	DrawFilledTriangle(vertex2, vertex3, vertex1, color_vertex2, color_vertex3, color_vertex1);
}

```

Com a chamada da função acima temos o resultado na imagem abaixo.

<p align="center">
  <img src ="./post_images/filled_triangle.png" />
  <h5 align="center">Figura #</h5>
</p>

Assim obtendo um resultado satisfatorio, um triângulo totalmente preenchido e sem pontos falhos.

---

## Dificuldades

---

## Possiveis trabalhos futuros

* Assim como o atributo ```buffer_line``` nos objetos da classe ```Line```,  o incremento de cor para o próximo ponto na interpolação de cores também poderia se tornar variavel de instancia da classe. Assim evitando calcular novamente quando feito o preenchimento de triângulos.

---

## Conclusão

---

## Referências

* [Bjarne Stroustrup's C++ Style and Technique FAQ](http://www.stroustrup.com/bs_faq2.html)

* [Bresenham's line algorithm - Wikipedia](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm)

* [Diogo Dantas](http://www.assignmentcg.blog.com/)

* [Felipe Alves - Rasterização](https://sites.google.com/site/felipealvesaraujocg/trabalho1)

* [Francisco Matheus - Pipeline Gráfico](http://franciscosouzacg.blogspot.com.br/)

* [Gabriel Soares - TrabalhoICG](https://soaresgabriel.github.io/TrabalhoICG/)

* [Jorismar Barbosa - Rasterização de Pontos e Linhas](http://jorismarbarbosa.blogspot.com.br/)

* Notas de Aula do Prof. Christian Pagot

* [Richelieu Costa - Triangulo, interpolação linear e preenchimento simples com bresenham](http://richelieucosta.wixsite.com/computacaografica/interpolacao-preenchimento-bresenham)

* [Shapari - Reflexão em torno da reta y = x](http://www.ufrgs.br/espmat/disciplinas/tutoriais_softwares/shapari/shapari_rfxy.htm)

* [The Bresenham Line-Drawing Algorithm - Department of Computer Science, University of Helsinki](https://www.cs.helsinki.fi/group/goa/mallinnus/lines/bresenh.html)

* [Transformações Lineares de Reflexão](http://www.feg.unesp.br/~anachiaradia/Material/Cap%2011-%20tipo%20de%20transformacao%20linear.pdf)




<!-- Place this tag in your head or just before your close body tag. -->
<script async defer src="https://buttons.github.io/buttons.js"></script>