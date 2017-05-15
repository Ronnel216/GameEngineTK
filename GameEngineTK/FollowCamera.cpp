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
	// �J�������_���W�A�Q�Ɠ_���W
	Vector3 eyepos;
	Vector3 refpos;

	refpos = targetPos + Vector3(0, 2, 0);

	// ���@�Ƃ̋���
	Vector3 cameraV(0, 0, CAMERA_DISTANCE);

	// �J�����̃x�N�g������]
	cameraV = Vector3().TransformNormal(cameraV, targetRota);
	eyepos = targetPos + Vector3(0, 2, 0) + cameraV;

	EyePos(eyepos);
	RefPos(refpos);

	Camera::Update();
}
