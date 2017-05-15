#include "HelloWorldScene.h"
#include <string>
#include <vld.h>
USING_NS_CC;

HelloWorld * SCENE = nullptr;

Scene* HelloWorld::createScene()
{
	return HelloWorld::create();
}
//Монстры
void HelloWorld::addZombieMusic()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	size_t SpawnX = (0.87*(rand() % 3 + 1))* visibleSize.width / 3;
	size_t SpawnY = 0.9*visibleSize.height;

	zombie1 = new TZombieMusic(SpawnX, SpawnY);
	TargetsVec.push_back(zombie1->GetModel());
	this->addChild(zombie1->GetModel(), 1);
	zombie1->Live();
}
void HelloWorld::addZombieWalker()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	size_t SpawnX = (0.87*(rand() % 3 + 1))* visibleSize.width / 3;
	size_t SpawnY = 0.9*visibleSize.height;

	zombie2 = new TZombieWalker(SpawnX, SpawnY);
	TargetsVec.push_back(zombie2->GetModel());
	this->addChild(zombie2->GetModel(), 1);
	zombie2->Live();
}
void HelloWorld::addPudge()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	size_t SpawnX = visibleSize.width / 2;
	size_t SpawnY = 0.9*visibleSize.height;
	pudge = new TPudge(SpawnX, SpawnY, "Puuudge.png");
	TargetsVec.push_back(pudge->GetModel());
	this->addChild(pudge->GetModel(), 1);
	pudge->ChopChop();
}
void HelloWorld::addSkeletonSword()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	size_t SpawnX = (0.87*(rand() % 3 + 1))* visibleSize.width / 3;
	size_t SpawnY = 0.9*visibleSize.height;

	skeleton1 = new TSkeletonSword(SpawnX, SpawnY);
	TargetsVec.push_back(skeleton1->GetModel());
	this->addChild(skeleton1->GetModel(), 1);
	skeleton1->Live();
	
}
void HelloWorld::addSkeletonSpear()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	size_t SpawnX = (0.87*(rand() % 3 + 1))* visibleSize.width / 3;
	size_t SpawnY = 0.9*visibleSize.height;

	skeleton2 = new TSkeletonSpear(SpawnX, SpawnY);
	TargetsVec.push_back(skeleton2->GetModel());
	this->addChild(skeleton2->GetModel(), 1);
	skeleton2->Live();
}

//Действия героя
void HelloWorld::Incineration()
{
	if (this->Score >= 75)
	{
		for (size_t jt = 0; jt < TargetsVec.size(); jt++)
		{
			SCENE->removeChild(TargetsVec[jt], 1);
		}
		Score -= 75;
		TargetsVec.clear();
	}
}
void HelloWorld::HealHouse()
{
	if (this->Score >= 100)
	{
		Score -= 100;
		player->Heal();
	}
}
void HelloWorld::Shoot()
{
	if (!End)
	{
		auto bullet = Sprite::create("bullet.png");
		bullet->setPosition(Vec2(SCENE->player->GetModelWidth() / 2, SCENE->player->GetModelHeight()));
		SCENE->player->GetModel()->addChild(bullet, 1);

		Bullets.push_back(bullet);
		auto Shoot = MoveBy::create(0.5, Vec2(0, 400));
		bullet->runAction(Shoot);
	}
}
//Обработка сообщений от клавиатуры (движение, стрельба, лечение)
void Actions(cocos2d::EventKeyboard::KeyCode code, cocos2d::Event * event)
{
	if (SCENE == nullptr)
		return;

	if (code == cocos2d::EventKeyboard::KeyCode::KEY_D)
	{
		if (SCENE->player->GetX() <= 4.7*Director::getInstance()->getVisibleSize().width / 6)
		{
			SCENE->player->MoveRight();
		}
	}
	if (code == cocos2d::EventKeyboard::KeyCode::KEY_U)
	{
		SCENE->Shoot();
	}
	if (code == cocos2d::EventKeyboard::KeyCode::KEY_A)
	{
		if (SCENE->player->GetX() >= Director::getInstance()->getVisibleSize().width / 3)
		{
			SCENE->player->MoveLeft();
		}
	}
	if (code == cocos2d::EventKeyboard::KeyCode::KEY_H)
	{
		SCENE->HealHouse();
	}
	if (code == cocos2d::EventKeyboard::KeyCode::KEY_J)
	{
		SCENE->Incineration();
	}
}

//Апдейты
void HelloWorld::UpdateShoot(float dt)
{
	for (auto it = Bullets.begin(); it != Bullets.end(); ++it)
	{
		auto bullet = *it;
		CCSize bulletSize = bullet->getContentSize();
		CCRect bulletRect = CCRectMake(SCENE->player->GetModel()->getPosition().x - (bulletSize.width / 2),
			bullet->getPosition().y - (bulletSize.height / 2),
			bulletSize.width, bulletSize.height);
		for (auto jt = TargetsVec.begin(); jt != TargetsVec.end(); jt++)
		{
			auto target = *jt;
			CCSize targetSize = target->getContentSize();
			CCRect targetRect = CCRectMake(target->getPosition().x - (targetSize.width / 2),
				target->getPosition().y - (targetSize.height / 2),
				targetSize.width, targetSize.height);

			if (bulletRect.intersectsRect(targetRect))
			{
				TargetsVec.erase(jt);
				SCENE->removeChild(target, 1);
				
				Bullets.erase(it);
				SCENE->player->GetModel()->removeChild(bullet, 1);
				Score++;
				return;
			}
		}
	}
}
void HelloWorld::Update(float dt)
{
	if (!End)
	{
		//Удаление пуль, вышедших за границы окна
		for (auto it = Bullets.begin(); it != Bullets.end(); ++it)
		{
			auto bullet = *it;
			if (bullet->getPositionY() > Director::getInstance()->getVisibleSize().height)
			{
				Bullets.erase(it);
				SCENE->player->GetModel()->removeChild(bullet, 1);
				break;
			}
		}
		//Обновление показателя здоровья дома и убитых монстров (левая нижняя часть экрана)
		HP->setString(std::to_string(player->GetLifes()));
		Scores->setString(std::to_string(Score));
		//Столкновение монстров с домом, их удаление и получение урона игроком
		for (auto jt = TargetsVec.begin(); jt != TargetsVec.end(); jt++)
		{
			auto target = *jt;
			if (target->getPositionY() <= Director::getInstance()->getVisibleSize().height / 5)
			{
				player->GetDamage(1);
				TargetsVec.erase(jt);
				SCENE->removeChild(target, 1);
				target = nullptr;
				break;
			}
		}
		if (player->GetLifes() <= 0)
		{
			End = true;
			
			//Надпись о проигрыше
			auto GameOver = Label::create("You Lose! Zombies ate your brain:( ", "fonts/Marker Felt.ttf", 36);
			GameOver->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2,
				Director::getInstance()->getVisibleSize().height / 2));
			this->addChild(GameOver, 1);
			//Запись результата в файл
			Highscore.open("Highscores.txt", std::ios_base::app);
			if (Highscore.is_open())
			{
				Highscore << "Player - " << this->Score << " scores \n";
				Highscore.close();
			}
			
			return;
		}

	}
}
void HelloWorld::SpawnMonsters(float dt)
{
	if (!End)
	{
		size_t Monster = rand() % 5;
		switch (Monster)
		{
		case 0:
		{
			addZombieMusic();
			break;
		}
		case 1:
		{
			addZombieWalker();
			break;
		}
		case 2:
		{
			addPudge();
			break;
		}
		case 3:
		{
			addSkeletonSword();
			break;
		}
		case 4:
		{
			addSkeletonSpear();
			break;
		}
		}
	}
}


bool HelloWorld::init()
{
   
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto background = Sprite::create("BackGround.png");
	background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(background, 0);

    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

	player = new THero(visibleSize.width/2, visibleSize.height/6);
	this->addChild(player->GetModel(), 1);
	SCENE = this;
#pragma region 
	auto label = Label::create("Lifes: ", "fonts/Marker Felt.ttf", 18);
	label->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 15,
		Director::getInstance()->getVisibleSize().height / 2 - label->getContentSize().height));
	this->addChild(label, 1);
	auto killed = Label::create("Score: ", "fonts/Marker Felt.ttf", 18);
	killed->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 15,
		Director::getInstance()->getVisibleSize().height / 2.5 - label->getContentSize().height));
	this->addChild(killed, 1);

	HP = Label::create("%HP", "fonts/Marker Felt.ttf", 18);
	HP->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 8,
		Director::getInstance()->getVisibleSize().height / 2 - HP->getContentSize().height));
	this->addChild(HP, 1);
	Scores = Label::create("%Sc", "fonts/Marker Felt.ttf", 18);
	Scores->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 7,
		Director::getInstance()->getVisibleSize().height / 2.5 - Scores->getContentSize().height));
	this->addChild(Scores, 1);
#pragma endregion
	
	cocos2d::EventListenerKeyboard * listener = cocos2d::EventListenerKeyboard::create();
	listener->onKeyPressed = Actions;
	
	this->schedule(schedule_selector(HelloWorld::SpawnMonsters), 0.5);
	this->schedule(schedule_selector(HelloWorld::UpdateShoot), 0.05);
	this->schedule(schedule_selector(HelloWorld::Update), 0.1);

	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    return true;
}
HelloWorld::~HelloWorld()
{
	delete player;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

