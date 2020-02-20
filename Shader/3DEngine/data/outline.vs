////////////////////////////////////////////////////////////////////////////////
// Filename: outline.vs
////////////////////////////////////////////////////////////////////////////////


/////////////
// GLOBALS //
/////////////
cbuffer MatrixBuffer
{
	matrix worldMatrix;
	matrix viewMatrix;
	matrix projectionMatrix;
	matrix worldInverse;
};


//////////////
// TYPEDEFS //
//////////////
struct VertexInputType
{
    float4 position : POSITION;
    float2 tex : TEXCOORD0;
    float4 normal : NORMAL;
    float4 color : COLOR;
};

struct PixelInputType
{
    float4 position : SV_POSITION;
    float2 tex : TEXCOORD0;
    float3 normal : TEXCOORD1;
    float4 color : COLOR;
};


////////////////////////////////////////////////////////////////////////////////
// Vertex Shader
////////////////////////////////////////////////////////////////////////////////
PixelInputType OutlineShaderVertexShader(VertexInputType input)
{
    PixelInputType output;

	// Change the position vector to be 4 units for proper matrix calculations.
    input.position.w = 1.0f;

	// Calculate the position of the vertex against the world, view, and projection matrices.
	float4 outputPos = mul(input.position, worldMatrix);
    outputPos = mul(outputPos, viewMatrix);
    outputPos = mul(outputPos, projectionMatrix);
    
	float lineThickness = 3.0;
	
	matrix worldInverseTranspose = transpose(transpose(worldInverse));
    
	// Transform the normal
	float4 normal = normalize(mul(input.normal, worldInverseTranspose));
	output.normal = normal;

	output.position = outputPos  + (mul(lineThickness, normal));

 
	// Store the input color for the pixel shader to use.
    output.color = input.color;
    
	// Store the texture coordinates for the pixel shader.
	output.tex = input.tex;

    return output;
}