/// <summary>
/// #pragma once
/// </summay>

#include <d3d11.h>
#include <SimpleMath.h>

class Camera
{
private:
public:
	Camera(int width, int height);


	virtual ~Camera();

	// �X�V
	void Update();


	// �r���[�s���Ԃ�
	const DirectX::SimpleMath::Matrix& View() const{
		return view;
	}

	// �v���W�F�N�V�����s���Ԃ�
	const DirectX::SimpleMath::Matrix& Proj() const{
		return proj;
	};

	// �n�_���W�̃Z�b�g
	void EyePos(DirectX::SimpleMath::Vector3 eyePos){
		this->eyePos = eyePos;
	};

	// �Q�Ɠ_�̃Z�b�g
	void RefPos(DirectX::SimpleMath::Vector3 refPos) {
		this->refPos = refPos;
	};

	// �J�����̏�����x�N�g��
	void VpVec(DirectX::SimpleMath::Vector3 vpVec) {
		this->vpVec = vpVec;
	};
	// �r���[�s��
	void View(DirectX::SimpleMath::Matrix view) {
		this->view = view;
	};
	// �v���W�F�N�V�����s��
	void Proj(DirectX::SimpleMath::Matrix proj) {
		this->proj = proj;
	};
	// ����p
	void FovY(float fovY) {
		this->fovY = fovY;
	};
	// �A�X�y�N�g��
	void Aspect(float aspect) {
		this->aspect = aspect;
	};
	// �j�A�N���b�v
	void NearClip(float nearClip) {
		this->nearClip = nearClip;
	};
	// �t�@�[�N���b�v
	void FarClip(float farClip) {
		this->farClip = farClip;
	};


protected:
	// �J�����̈ʒu
	DirectX::SimpleMath::Vector3 eyePos;
	// �J�����̌��Ă����(�����_/�Q�Ɠ_)
	DirectX::SimpleMath::Vector3 refPos;
	// �J�����̏�����x�N�g��
	DirectX::SimpleMath::Vector3 vpVec;
	// ����p
	float fovY;
	// �A�X�y�N�g��
	float aspect;
	// �j�A�N���b�v
	float nearClip;
	// �t�@-�N���b�v
	float farClip;

	// �r���[�s��
	DirectX::SimpleMath::Matrix view;
	// �v���W�F�N�V�����s��
	DirectX::SimpleMath::Matrix proj;
};

