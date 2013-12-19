#include "MyGame.h"
#include "..\D3D10Renderer\D3D10Renderer.h"

bool MyGame::initGame()
{
	CubeVisualComponent *pCube=new CubeVisualComponent();
	pCube->create(m_pRenderer);
	
	Material *pMaterial=new Material();
	pMaterial->loadEffect("Effects/DirectionalLight.fx",m_pRenderer);

	DirectionalLight *pDirLight=new DirectionalLight();

	GameObject *pTestObj=new GameObject();
	pTestObj->setName("TestObject");
	pTestObj->addComponent(pCube);
	pTestObj->addComponent(pMaterial);
	pTestObj->addComponent(pDirLight);

	pCube->createVertexLayout(m_pRenderer);
	
	pTestObj->getTransform().setPosition(2.0f,1.0f,1.0f);

	m_GameObjectList.push_back(pTestObj);
	//set main light



	pCube=new CubeVisualComponent();
	pCube->create(m_pRenderer);
	
	pMaterial=new Material();
	pMaterial->loadEffect("Effects/Texture.fx",m_pRenderer);
	pMaterial->loadDiffuseTexture("Textures/Spotlight.jpg",m_pRenderer);

	pTestObj=new GameObject();
	pTestObj->setName("TestObject1");
	pTestObj->addComponent(pCube);
	pTestObj->addComponent(pMaterial);

	pCube->createVertexLayout(m_pRenderer);
	
	pTestObj->getTransform().setPosition(-0.5f,1.0f,1.0f);

	m_GameObjectList.push_back(pTestObj);

	CameraComponent *pCameraComp=new CameraComponent();
	pCameraComp->setLook(0.0f,0.0f,0.0f);
	pCameraComp->setFOV(m_GameOptionDesc.width/m_GameOptionDesc.height);
	//Create Camera
	GameObject *pCameraGO=new GameObject();
	pCameraGO->setName("MainCamera");
	pCameraGO->addComponent(pCameraComp);
	setMainCamera(pCameraComp);
	pCameraGO->getTransform().setPosition(0.0f,0.0f,-10.0f);

	m_GameObjectList.push_back(pCameraGO);

	GameObject *pCar=m_ModelLoader.loadModelFromFile("Models/armoredrecon.fbx",m_pRenderer);
	for(GameObject::ChildrenGameObjectsIter iter=pCar->getFirstChild();iter!=pCar->getLastChild();iter++)
	{
		pMaterial=new Material();
		pMaterial->loadEffect("Effects/Texture.fx",m_pRenderer);
		pMaterial->loadDiffuseTexture("Textures/armoredrecon_diff.png",m_pRenderer);
		iter->second->addComponent(pMaterial);
		VisualComponent *pVisual=static_cast<VisualComponent*>(iter->second->getComponent("Visual"));
		pVisual->createVertexLayout(m_pRenderer);
	}

	m_GameObjectList.push_back(pCar);


	D3D10Renderer *pD3D10Renderer=static_cast<D3D10Renderer*>(m_pRenderer);
	//send the game object which has the light
	//pD3D10Renderer->setMainLight(pLightObject)
	//send the game object which has the camera
	pD3D10Renderer->setMainCamera(pCameraGO);
	return true;
}