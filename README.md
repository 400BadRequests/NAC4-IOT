# Nome do projeto
NAC 04 -  IOT

**nome dos alunos:**
Luiz Phelipe - 86330,
Christian Chang - 86360,
Paulo Sérgio- 85873,
Gabriel Silva - 86404 e 
Caio Augusto - 82953

**Turma:**
2TDSJ

**Ano:**
2021

## Objetivo / descrição do Projeto
Projeto dedicado a NAC 04, da materia de IOT do curso de analise e desenvolvimento de sistemas. Suas caracteristicas: Leitura de três sensores LDR(luminosidade), termistor(Temperatura) e Gerador de função(Frequencia), enviados via comunicação serial e postados em um topico MQTT, recuperados e salvos em um banco de dados na nuvem usando o serviço da ibm cloudant e por final caso a velocidade do vento seja maior que 80 km/h será postado um tweet no twitter avisando sobre.  

## Diagrama do projeto

Adicione uma ou mais fotos do projeto, pode ser uma imagem da arquitetura, do circuito eletrônico do Flow desenvolvido. 
<br><h3>Circuito eletrônico<br>
![image](https://user-images.githubusercontent.com/58408056/130545174-21f1f9f2-7ee5-42cd-bf26-00e4c8ba2cf3.png)<br>
<br><h3>Fluxo Node-Red <br>
![image](https://user-images.githubusercontent.com/58408056/130545191-d421157a-621a-462c-b218-80c1fbfb1050.png)<br>
<br><h3>Dashboard Node-Red UI<br>
![image](https://user-images.githubusercontent.com/58408056/130545216-2734ea3d-1f23-4011-a868-e05421228582.png)<br>


## Como usar 

Será necessario instalar o simulide, arduino, nodejs, node-red, junto com as bibliotecas de comunicação serial, mqtt e twitter.
Fazer copia do texto do arquivo node-red-json.txt e exportar no node-red.
Após fazer a instalação das libs necessárias


## Link de vídeo demonstração
https://youtu.be/EH22xWWueVk


### Referências 

* [mastering-markdown](https://guides.github.com/features/mastering-markdown/)
* [Basic writing and formatting syntax](https://docs.github.com/en/github/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax)
