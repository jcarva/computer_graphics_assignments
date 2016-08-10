# Pipeline Gráfico: Rasterização de Primitivas

---

## Introdução

Esta postagem é parte obrigatoria da primeira avaliação prática da disciplina de Introdução à Computação Gráfica, ministrada pelo Prof. Christian Pagot no semestre letivo 2016.1.

As definições e especificações projeto podem ser acessadas através deste [link](https://github.com/jcarva/rasterization/blob/master/project_definition.pdf).

Como explanado em sala de aula pelo professor, o conteúdo teórico extra atividade não precisa ser novamente descrito na postagem.

Todo o código citado está disponivel neste [repositorio público](https://github.com/jcarva/rasterization).

Caso o código ou a corrente postagem seja de alguma ajuda peço para que contribua com um "star" no repositorio público.

**Tem alguma questão ou sugestão?**																												
Contate-me no [Linkedin](https://www.linkedin.com/in/jaelson-carvalho-4b84a3a2?trk=nav_responsive_tab_profile_pic), envie um email para jaelsoncarvalhojr@gmail.com, ou crie um pull request neste projeto. Toda ajuda e qualquer é bem vinda.

---

## 1. Rasterização de Pontos
<br>
Rasterizar pontos é o trabalho de "escrever" tais pontos no colorbuffer, e que como resultado obtemos uma representação deste ponto na tela, que geralmente podemos denomina-lo pixel. Assim como na descrição matemática, em nosso caso cada ponto é formado por duas coordenadas, x e y que demarcam sua posição no espaço ou tela. Todo ponto representado na tela possui um cor, que é a informação registrada na memória de vídeo.
<br>
<br>
Antes de dar continuidade com a rasterização de pontos propriamente dita, é necessario que saibamos como de fato o colorbuffer. Podemos defini-lo como uma estrutura com espaço de coordenadas unidimensional. Sabendo que os pontos representados na tela possuem coordenadas bidimensionais, é necessario um mapeamento 2D => 1D para que possamos ter consistencia ao armazenarmos todos os pontos a serem escritos no colorbuffer.
<br>
<br>
Tal mapeamento supracitado pode ser obtido através da função Offset, descrita abaixo.

``` c++
int Pixel::Offset(int column, int row)
{
	return (column  + row * IMAGE_WIDTH) * 4;
}
```
Onde o argumento ```column``` representa a coordenada 'x' do ponto em um espaço bidimensional, e o argumento ```row``` representa a coordenada 'y' do mesmo ponto.

O valor de retorno da função Offset corresponde a posição do primeiro dos 4 bytes que guardam a cor do pixel em relação ao endereço do ponteiro do colorbuffer.
<br>
<br>
Você pode estar pensando : "***Como assim 4 bytes para uma cor?***"

Em nosso sistema um cor RGBA cada byte representa a intensidade das cores primarias usadas, sendo o primeiro byte para a cor vermelha(Red-R), e dando sequencia com verde(Green-G), azul(Blue-B) e Alpha-A(usado para transparência) respectivamente.

Sabendo disso, agora temos conhecimento suficiente para desenvolver a primeira das funções obrigatorias descritas na [especificação](https://github.com/jcarva/rasterization/blob/master/project_definition.pdf) do projeto, a função ***PutPixel***.

###PutPixel

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

Com a função acima devidamente implementada já podemos obter os primeiros resultados na tela, veja a as imagens abaixo.

---

## 2. Rasterização de Retas

---

## 3. Desenho de Triângulos

---

## 4. Preenchimento de Triângulos

---

## Dificuldades

---

## Conclusão

---

## Referências

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

---