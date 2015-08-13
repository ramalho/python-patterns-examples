
public abstract class SoapInvoker
{
    private Response   d_resp = null;
    private String     d_objectUri = null;
    private String     d_methodName = null;
    private String     d_encodingStyleURI = Constants.NS_URI_SOAP_ENC;
    private static URL s_url = null;
    private Vector     d_params = new Vector();
	
    protected abstract void setParams();
	
    public SoapInvoker(String objectUri, String methodName)
    {
        d_objectUri = objectUri;
        d_methodName = methodName;
    }

    public Object getResult()
    {
        return translate(d_resp);
    }

    private Object translate(Response resp)
    {
        Object rtnValue = null;

        if (!resp.generatedFault())
        {
            Parameter ret = resp.getReturnValue();
            rtnValue = SoapUtils.fromByteArray((byte[]) ret.getValue());
        }
        else
        {
            outputFault(d_methodName, resp);
        }

        return rtnValue;
    }

    public void invoke()
    {
		setParams();
		
        Call call = new Call();
        call.setTargetObjectURI(d_objectUri);
        call.setMethodName(d_methodName);
        call.setEncodingStyleURI(d_encodingStyleURI);
        call.setParams(d_params);

        try
        {
            d_resp = call.invoke(s_url, "");
        }
        catch (SOAPException e)
        {
            System.err.println("Caught SOAPException (" + e.getFaultCode() 
                               + "): " + e.getMessage());
        }

        if (d_resp.generatedFault())
        {
            outputFault(d_methodName, d_resp);
        }
    }

    private void outputFault(String methodName, Response resp)
    {
        Fault fault = resp.getFault();

        System.err.println("Generated fault (" + methodName + "()):");
        System.err.println("  Fault Code   = " + fault.getFaultCode());
        System.err.println("  Fault String = " + fault.getFaultString());
    }
}
