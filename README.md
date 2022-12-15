# RealSkinSimulation

<div align="center"><img src=https://user-images.githubusercontent.com/50454395/207859769-9785e302-9b0b-4b33-a62f-3054a3d2bba0.gif></div> 
<div align="center">Real Face Skin Deformation</div>

</br>

# Subject

> Real Skin Deformation
* 피부의 표현에 물리적 반응을 넣어서 충돌에 Dynamic하게 반응하도록 했습니다.
* 높은 퀄리티의 물리적인 반응 및 시뮬레이션이 가능합니다.
* 게임에 적용한다면 조금 더 퀄리티 높은 action sequence를 만들수 있습니다.

</br>

# Motivation
* AAA게임들을 보면 정말 화려한 액션과 연출로 게임에 재미를 추가해 줍니다.
* 하지만 피부 표현은 정말 고퀄리티지만 정작 피부의 물리적인 충돌은 표현되어 있지 않습니다.
* 저는 여기서 Reality skin physics를 만들어 보고 싶어서 시작하게 되었습니다.

</br>

# Target Paper
<div align="center"><img src=https://velog.velcdn.com/images/mmindoong/post/498a27f2-1b83-44aa-a4bc-8cefbaf012e2/image.png></div> 

</br>

* Detailed Rigid Body Simulation with Extended Position Based Dynamics </br>
https://matthias-research.github.io/pages/publications/PBDBodies.pdf 

* A Constraint-based Formulation of Stable Neo-Hookean Materials </br>
https://matthias-research.github.io/pages/publications/neohookean.pdf

</br>

#  Solution
## 1. Preprocessing
* 캐릭터들은 보통 bone이 정해져 있고 거기에 mesh(skin)가 따라옵니다.
* 피부가 접히는 부분에 preprocessing을 통해 조금 더 리얼하게 표현이 가능합니다.

## 2. Real Time
* Preprocessing과 다르게 따로 처리를 해주지 않습니다.
* Real time으로 mesh안의 particle끼리의 충돌을 계산하여 처리합니다.

## 3. Preprocessing + Realtime(My solution)
* Real time으로 mesh안의 particle끼리의 충돌을 계산하여 처리합니다.
* Preprocessing으로 했을 때 하나하나 다 처리해줘야 하는 불편함과 Real time으로 했을 때 texture가 깨지는 현상을 모두 해결할 수 있습니다.

</br>

# Math
## XPBD(Position Based-Compliant Constrained Dynamics)
</br>

<div align="center"><img src=https://user-images.githubusercontent.com/50454395/207864782-7f2301bf-972e-4748-aac5-5fd9c2bb0054.png></div> 
</br>

* Skin deformation을 위해서는 `XPBBD`가 들어갑니다.
* XPBD는 기존의 PBD를 논문에서 바꾼 것으로 skin deformation을 하기 위한 조금 더 효율적인 알고리즘입니다.

</br>

<div align="center"><img src=https://user-images.githubusercontent.com/50454395/207864952-b6b75472-c623-47cc-9c30-6fb345ec94c1.png></div> 
</br>

* XPBD의 Solve과정에서는 skin을 soft하게 만들어 주기 위해서 `Distant`와 `Volume Constraint` 작업을 진행합니다.
* `Constraint`는 mesh의 particle이 원래 위치에서 벗어나면 다시 원래 위치로 돌아가게끔 해주는 힘입니다.
* `Distant`는 particle사이의 edge거리에 따른 Constraint이고 `Volume`은 4개의 particle로 이루어진 사면체의 volume 크기에 따른 Constraint입니다.

</br>

# Mesh

> __Paper mesh VS Unreal mesh__

</br>

<div align="center"><img src=https://user-images.githubusercontent.com/70145314/207869041-207a2ca3-a2a4-414a-88f3-4e78c6c59c1a.png></div> 

### Paper Mesh
* `Tetrahedral Mesh` : Tet mesh라고 불리며 보통 논문에서 simulation을 할 때 많이 사용합니다.
* 속이 꽉 차 있어서 particle간의 simulation에 용이합니다.
### Unreal Mesh
* `Static Mesh` : 보통 Tri mesh를 많이 사용합니다.
* 속이 비어있는 mesh로 게임에서 많이 사용합니다(계산이 쉽고 간편합니다).

> __Paper Mesh To Unreal Mesh__
* Unreal Mesh를 Paper Mesh로 바꾸려고 blender의 `BlenderTetPlugin`을 Unreal에 가져와서 적용했습니다.
https://github.com/matthias-research/pages/blob/master/tenMinutePhysics/BlenderTetPlugin.py
* 하지만 왜인지 잘 안되었습니다...
* 그래서 어쩔 수 없이 Unreal mesh에서 논문의 기술을 사용하도록 논문 코드를 변형했습니다.
* Volume Constraint부분에서 Tet mesh는 particle이 안까지 꽉 차있기 때문에 particle간의 volume constraint가 잘 일어납니다. 하지만 Unreal mesh는 mesh안이 비어있기 때문에 Volume Constraint가 거의 일어나지 않습니다.
* 따라서 Vlume constraint부분을 수정하여 face constraint로 수정하였습니다.

</br>

# Result
</br>

## 1. Test - Mesh Deformation
</br>

<div align="center"><img src=https://user-images.githubusercontent.com/70145314/207869774-9ed11429-4071-40b4-9d19-87a2d709182f.gif></div> 

</br>

* Mesh Deformation을 Real time으로 실행해봤습니다.
* Mesh가 계획한 대로 탄력있게 튀어오르는 결과가 나왔습니다.
* 하지만 Real skin으로 보기에는 너무 결과가 Dynamic해서 조금 static하게 optimization을 해줘야 합니다. 

</br>

## 2. Optimization
</br>
<div align="center"><img src=https://user-images.githubusercontent.com/70145314/207870588-914461a3-1351-43ef-a858-b274555d19de.png width="600"></div> 

</br>

* Skin과 Bone을 설정해서 늘어날 때는 skin보다 늘어나지 못하고, 줄어들 때는 bone보다 줄어들지 못하게 preprocessing을 진행했습니다.

</br>

> __Optimization Result__

</br>

<div align="center"><img src=https://user-images.githubusercontent.com/70145314/207873253-b3f62f7d-f9ed-4861-b87a-9f3cd326de1b.gif></div> 

</br>

## 3. Game Application

<div align="center"><img src=https://user-images.githubusercontent.com/70145314/207874119-34b563be-b790-462f-808e-67c0ca8bc4a8.gif width="300"></div> 


# Demo
> Demo video 
https://youtu.be/kvyevt88Fio
