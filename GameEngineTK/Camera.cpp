
#include "Camera.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

// �����o�ϐ��̏�����
Camera::Camera(int width, int height)
	: eyePos(Vector3().Zero)
	, refPos(eyePos + Vector3(0.f, 0.f, 1.f))
	, vpVec(Vector3(0.f, 1.f, 0.f))
	, fovY(XM_PIDIV4)
	, aspect(static_cast<float>(width) / height)
	, nearClip(0.1f)
	, farClip(1000.0f)
	, view(Matrix::CreateLookAt(eyePos, refPos, vpVec))
	, proj(Matrix::CreatePerspectiveFieldOfView(fovY, aspect, nearClip, farClip))
{
	// ������Ԃ� �r���[�s��@�v���W�F�N�V�����s�� ����
	view = Matrix::CreateLookAt(eyePos, refPos, vpVec);
	proj = Matrix::CreatePerspectiveFieldOfView(fovY, aspect, nearClip, farClip);

}

Camera::~Camera()
{
}

void Camera::Update()
{
	// �s��̐����@�v�Z
	view = Matrix::CreateLookAt(eyePos, refPos, vpVec);
	proj = Matrix::CreatePerspectiveFieldOfView(fovY, aspect, nearClip, farClip);
}
