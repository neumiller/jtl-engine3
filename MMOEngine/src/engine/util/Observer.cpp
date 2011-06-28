/*
 *	engine/util/Observer.cpp generated by engine3 IDL compiler 0.60
 */

#include "Observer.h"

#include "engine/log/Logger.h"

#include "engine/util/Observable.h"

/*
 *	ObserverStub
 */

enum {RPC_NOTIFYOBSERVEREVENT__INT_OBSERVABLE_MANAGEDOBJECT_LONG_ = 6,RPC_GETOBJECTID__,RPC_COMPARETO__OBSERVER_};

Observer::Observer(DummyConstructorParameter* param) : ManagedObject(param) {
}

Observer::~Observer() {
}


int Observer::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	ObserverImplementation* _implementation = (ObserverImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_NOTIFYOBSERVEREVENT__INT_OBSERVABLE_MANAGEDOBJECT_LONG_);
		method.addUnsignedIntParameter(eventType);
		method.addObjectParameter(observable);
		method.addObjectParameter(arg1);
		method.addSignedLongParameter(arg2);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->notifyObserverEvent(eventType, observable, arg1, arg2);
}

unsigned long long Observer::getObjectID() {
	ObserverImplementation* _implementation = (ObserverImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETOBJECTID__);

		return method.executeWithUnsignedLongReturn();
	} else
		return _implementation->getObjectID();
}

int Observer::compareTo(Observer* obj) {
	ObserverImplementation* _implementation = (ObserverImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_COMPARETO__OBSERVER_);
		method.addObjectParameter(obj);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->compareTo(obj);
}

DistributedObjectServant* Observer::_getImplementation() {

	_updated = true;
	return _impl;
}

void Observer::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	ObserverImplementation
 */

ObserverImplementation::ObserverImplementation() : ManagedObjectImplementation() {
	_initializeImplementation();
}

ObserverImplementation::ObserverImplementation(DummyConstructorParameter* param) : ManagedObjectImplementation(param) {
	_initializeImplementation();
}


ObserverImplementation::~ObserverImplementation() {
}


void ObserverImplementation::finalize() {
}

void ObserverImplementation::_initializeImplementation() {
	_setClassHelper(ObserverHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void ObserverImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (Observer*) stub;
	ManagedObjectImplementation::_setStub(stub);
}

DistributedObjectStub* ObserverImplementation::_getStub() {
	return _this;
}

ObserverImplementation::operator const Observer*() {
	return _this;
}

void ObserverImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void ObserverImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void ObserverImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void ObserverImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void ObserverImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void ObserverImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void ObserverImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void ObserverImplementation::_serializationHelperMethod() {
	ManagedObjectImplementation::_serializationHelperMethod();

	_setClassName("Observer");

}

void ObserverImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(ObserverImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool ObserverImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ManagedObjectImplementation::readObjectMember(stream, _name))
		return true;


	return false;
}

void ObserverImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = ObserverImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int ObserverImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;

	return 0 + ManagedObjectImplementation::writeObjectMembers(stream);
}

int ObserverImplementation::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	// engine/util/Observer.idl():  		return 1;
	return 1;
}

int ObserverImplementation::compareTo(Observer* obj) {
	// engine/util/Observer.idl():  			return 0;
	if (getObjectID() < obj->getObjectID())	// engine/util/Observer.idl():  			return 1;
	return 1;

	else 	// engine/util/Observer.idl():  			return 0;
	if (getObjectID() > obj->getObjectID())	// engine/util/Observer.idl():  			return -1;
	return -1;

	else 	// engine/util/Observer.idl():  			return 0;
	return 0;
}

/*
 *	ObserverAdapter
 */

ObserverAdapter::ObserverAdapter(ObserverImplementation* obj) : ManagedObjectAdapter(obj) {
}

Packet* ObserverAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_NOTIFYOBSERVEREVENT__INT_OBSERVABLE_MANAGEDOBJECT_LONG_:
		resp->insertSignedInt(notifyObserverEvent(inv->getUnsignedIntParameter(), (Observable*) inv->getObjectParameter(), (ManagedObject*) inv->getObjectParameter(), inv->getSignedLongParameter()));
		break;
	case RPC_GETOBJECTID__:
		resp->insertLong(getObjectID());
		break;
	case RPC_COMPARETO__OBSERVER_:
		resp->insertSignedInt(compareTo((Observer*) inv->getObjectParameter()));
		break;
	default:
		return NULL;
	}

	return resp;
}

int ObserverAdapter::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	return ((ObserverImplementation*) impl)->notifyObserverEvent(eventType, observable, arg1, arg2);
}

unsigned long long ObserverAdapter::getObjectID() {
	return ((ObserverImplementation*) impl)->getObjectID();
}

int ObserverAdapter::compareTo(Observer* obj) {
	return ((ObserverImplementation*) impl)->compareTo(obj);
}

/*
 *	ObserverHelper
 */

ObserverHelper* ObserverHelper::staticInitializer = ObserverHelper::instance();

ObserverHelper::ObserverHelper() {
	className = "Observer";

	Core::getObjectBroker()->registerClass(className, this);
}

void ObserverHelper::finalizeHelper() {
	ObserverHelper::finalize();
}

DistributedObject* ObserverHelper::instantiateObject() {
	return new Observer(DummyConstructorParameter::instance());
}

DistributedObjectServant* ObserverHelper::instantiateServant() {
	return new ObserverImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ObserverHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ObserverAdapter((ObserverImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

