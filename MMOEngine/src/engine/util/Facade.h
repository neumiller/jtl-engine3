/*
 *	engine/util/Facade.h generated by engine3 IDL compiler 0.60
 */

#ifndef FACADE_H_
#define FACADE_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

#include "engine/core/ManagedObject.h"

#include "engine/log/Logger.h"

namespace engine {
namespace util {

class Facade : public ManagedObject {
public:
	Facade();

	int initializeSession();

	int cancelSession();

	int clearSession();

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	Facade(DummyConstructorParameter* param);

	virtual ~Facade();

	friend class FacadeHelper;
};

} // namespace util
} // namespace engine

using namespace engine::util;

namespace engine {
namespace util {

class FacadeImplementation : public ManagedObjectImplementation, public Logger {

public:
	FacadeImplementation();

	FacadeImplementation(DummyConstructorParameter* param);

	virtual int initializeSession();

	virtual int cancelSession();

	virtual int clearSession();

	WeakReference<Facade*> _this;

	operator const Facade*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~FacadeImplementation();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();
	bool readObjectMember(ObjectInputStream* stream, const String& name);
	int writeObjectMembers(ObjectOutputStream* stream);

	friend class Facade;
};

class FacadeAdapter : public ManagedObjectAdapter {
public:
	FacadeAdapter(FacadeImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	int initializeSession();

	int cancelSession();

	int clearSession();

};

class FacadeHelper : public DistributedObjectClassHelper, public Singleton<FacadeHelper> {
	static FacadeHelper* staticInitializer;

public:
	FacadeHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<FacadeHelper>;
};

} // namespace util
} // namespace engine

using namespace engine::util;

#endif /*FACADE_H_*/
