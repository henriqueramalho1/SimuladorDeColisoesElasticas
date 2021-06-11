Simulador de Colisões Elásticas

O programa roda no Sistema Operacional Windows de arquitetura x64.
O compilador utilizado é o padrão do VisualStudio 2019: MSVC 15.8 ou também chamado de Microsoft C/C++.
Foi utilizada a biblioteca gráfica SFML 2.5.1


Para preparar o ambiente Visual Studio 2019,
ver tutorial: https://youtu.be/YfMQyOw1zik?t=35
ou
eis um passo a passo:
1) Vá até as propriedades de projeto
2) Selecione "All Configurations"
3) Selecionar C/C++ e adicionar o caminho da pasta include do SFML em "Additional Include Directories"
4) Selecionar Linker e adicionar o caminho da pasta lib do SFML em "Additional Library Directories"
5) Linker->Input e adicionar:

sfml-graphics-d.lib
sfml-window-d.lib
sfml-audio-d.lib
sfml-network-d.lib
sfml-system-d.lib

para a configuração Debug e

sfml-graphics.lib
sfml-window.lib
sfml-audio.lib
sfml-network.lib
sfml-system.lib

para a configuração Release.