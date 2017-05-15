#include "FollowCamera.h"

using namespace DirectX::SimpleMath;

const float FollowCamera::CAMERA_DISTANCE = 5.0f;

FollowCamera::FollowCamera(int width, int height, DirectX::SimpleMath::Vector3 targetPos, DirectX::SimpleMath::Matrix targetRota)
	: Camera(width, height)
	, targetPos(targetPos)
	, targetRota(targetRota)
{
}

void FollowCamera::Update() {
	// カメラ視点座標、参照点座標
	Vector3 eyepos;
	Vector3 refpos;

	refpos = targetPos + Vector3(0, 2, 0);

	// 自機との距離
	Vector3 cameraV(0, 0, CAMERA_DISTANCE);

	// カメラのベクトルを回転
	cameraV = Vector3().TransformNormal(cameraV, targetRota);
	eyepos = targetPos + Vector3(0, 2, 0) + cameraV;

	EyePos(eyepos);
	RefPos(refpos);

	Camera::Update();
}
