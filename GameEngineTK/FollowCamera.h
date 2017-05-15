/* ターゲットに追従するカメラ
date	: 2017/05/15
author	: Ryuna Tsuji
*/

#pragma once

#include <d3d11_1.h>
#include <SimpleMath.h>
#include "Camera.h"
#include "Class\Object3D.h"

class FollowCamera : public Camera {
public:
	static const float CAMERA_DISTANCE;

	FollowCamera(int width, int height, DirectX::SimpleMath::Vector3 targetPos, DirectX::SimpleMath::Matrix targetRota);

	void Update() override;

	void TargetPos(const DirectX::SimpleMath::Vector3& targetPos) {
		this->targetPos = targetPos;
	}

	void TargetRota(const DirectX::SimpleMath::Matrix& targetRota) {
		this->targetRota = targetRota;
	}


private:
	DirectX::SimpleMath::Vector3 targetPos;
	DirectX::SimpleMath::Matrix targetRota;



};
