#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include <TCreature.h>
#include <THero.h>
#include <TZombie.h>
#include <TZombieWalker.h>
#include <TZombieMusic.h>
#include <TPudge.h>
#include <TSkeleton.h>
#include <TSkeletonSword.h>
#include <TSkeletonSpear.h>
#include <vector>
#include <iostream>
#include <fstream>
#include "TRaii.h"
USING_NS_CC;

class HelloWorld 
	: public cocos2d::Scene
{	
	//Лейблы, отображающие здоровье и набранные очки
	Label* HP;
	Label* Scores;

	//Векторы спрайтов (используется для уничтожения)
	std::vector<Sprite*> TargetsVec;
	std::vector<Sprite*> Bullets;

	bool End = false; //Если истина - новые персонажи не спавнятся, стрельба запрещена. Можно только выйти из игры
	size_t Score = 0; 
	std::ofstream Highscore; // Для сохранения результатов
	// Монстры
	TRaii skeleton1;
	TRaii skeleton2;
	TRaii pudge;
	TRaii zombie2;
	TRaii zombie1;
public:
	
	THero* player;
	~HelloWorld();
	
	void Shoot();
	void HealHouse();
	void Incineration();

    static cocos2d::Scene* createScene();
	size_t WindowWidth = 0;
    virtual bool init();
    void menuCloseCallback(cocos2d::Ref* pSender);

	void addZombieMusic();
	void addZombieWalker();
	void addSkeletonSword();
	void addSkeletonSpear();
	void addPudge();

	void Update(float dt);
	void UpdateShoot(float dt);
	void SpawnMonsters(float dt);
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
