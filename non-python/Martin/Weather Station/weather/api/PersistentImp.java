package api;

import java.io.Serializable;
import java.util.AbstractList;

public interface PersistentImp
{
  void store(String name, Serializable obj) throws StoreException; 
  Object retrieveObject(String name) throws RetrieveException;
  AbstractList directory(String regExp) throws RetrieveException;
}
