/* Object3D�N���X��`
author : Ryuna Tsuji
*/

#pragma once

#include <Model.h>
#include <PrimitiveBatch.h>
#include <VertexTypes.h>
#include <Effects.h>
#include <CommonStates.h>
#include <SimpleMath.h>

class Object3D {
private:
	// �s��
	// ���[���h
	DirectX::SimpleMath::Matrix _world;
	// �r���[
	DirectX::SimpleMath::Matrix _view;
	// �v���W�F�N�V����
	DirectX::SimpleMath::Matrix _proj;
	// ���f��
	const DirectX::Model& _model;

	// �R���X�g���N�^
	Object3D(const DirectX::Model& model);

public:
	// �f�X�g���N�^
	~Object3D();

	// ����
	static Object3D* Create(const DirectX::Model& model);

	// �X�V
	void Update();

	// �`��
	void Render() const;

	// ���s�ړ�
	DirectX::SimpleMath::Vector3 pos;
	// ��]�s��
	DirectX::SimpleMath::Matrix rota;
	// �g��k��
	DirectX::SimpleMath::Matrix scale;

	// ���[���h�s��
	const DirectX::SimpleMath::Matrix& world() const {
		return _world;
	}
	void world(DirectX::SimpleMath::Vector3 pos) {
		_world = DirectX::SimpleMath::Matrix::CreateTranslation(pos);
	}
	void world(DirectX::SimpleMath::Matrix matrix) {
		_world = matrix;
	}

	// ���f���f�[�^
	const DirectX::Model& model() const {
		return _model;
	}

};
