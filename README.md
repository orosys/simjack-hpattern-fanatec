# SIM JACK H-Pattern Shifter Interface for FANATEC Wheelbase

SIM JACK H-Pattern Shifter를 파나텍 휠베이스에 사용할 수 있는 방법을 소개합니다.
아래 게시물을 참고하여 만들었습니다.
https://www.diy-sim.com/guides/projects/item/universal-fanatec-shifter-interface

## Getting Started
SIM JACK에서 발생되는 변속 정보를 파나텍 변속 신호에 맞게 변환하는 작업을 아두이노를 통해서 이루워집니다.

#### SIM JACK H-Pattern Shifter
SIM JACK의 경우 각 기어 위치 정보를 Hall Effect Switch Sensor(CC6201)를 통해 인식합니다.
![cc6201](https://github.com/orosys/simjack-hpattern-fanatec/blob/main/images/1.png?raw=true)
![cc6201](https://github.com/orosys/simjack-hpattern-fanatec/blob/main/images/3.png?raw=true)

자석을 근처에 가져가면 신호 값이 '0'으로 출력되므로 선택된 기어 정보를 가져올 수 있습니다.

![cc6201](https://github.com/orosys/simjack-hpattern-fanatec/blob/main/images/2.png?raw=true)

각 핀 정보는 이미지를 참고하세요.

#### ARDUINO
SIM JACK로 부터 가져온 정보를 FANATEC 기어 정보에 맞게 변환합니다.
각 위상에 맞게 Digtal 신호를 출력합니다.
![FANATEC](https://www.diy-sim.com/images/articles/projects/fanatec-shifter-interface/resistance_graph.jpg)

![cc6201](https://github.com/orosys/simjack-hpattern-fanatec/blob/main/images/4.png?raw=true)


## Wire
Arduino NANO를 사용함.

#### Input
- A1 - SIM JACK Shifter 1
- A2 - SIM JACK Shifter 2
- A3 - SIM JACK Shifter 3
- A4 - SIM JACK Shifter 4
- A5 - SIM JACK Shifter 5
- A6 - SIM JACK Shifter 6
- A0 - SIM JACK Shifter R

#### Output
- D2 - 910 Ohm -> 1N4148 -> Y1 pos
- D3 - 4.7K Ohm -> 1N4148 -> Y2 pos
- D4 - 20K Ohm -> 1N4148 -> Y3 pos
- D5 - 0 Ohm -> 1N4148 -> X1 pos
- D6 - 2.2K Ohm -> 1N4148 -> X2 pos
- D7 - 4.2K Ohm -> 1N4148 -> X3 pos
- D8 - 6.2K Ohm -> 1N4148 -> X4 pos
- D9 - 10K Ohm -> 1N4148 -> X5 pos
![cc6201](https://www.diy-sim.com/images/articles/projects/fanatec-shifter-interface/axis_voltage_dividers.jpg)
![cc6201](https://github.com/orosys/simjack-hpattern-fanatec/blob/main/images/5.png?raw=true)


![cc6201](https://github.com/orosys/simjack-hpattern-fanatec/blob/main/images/6.png?raw=true)

<a href="https://youtu.be/ua-j_5fWz2A?si=evXa0Udz4UIqJKA9">
	<img src="https://i3.ytimg.com/vi/ua-j_5fWz2A?si=evXa0Udz4UIqJKA9/maxresdefault.jpg"/>
</a>
